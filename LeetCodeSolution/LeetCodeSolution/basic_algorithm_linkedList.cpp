#include <iostream>
#include "basic_algorithm_linkedList.h"
using namespace std;


/***************文件说明*************
* 文件名：basic_algorithm_linkedList.cpp
* 文件功能：LeetCode初级算法链表部分

**/
/***************函数说明*************
* 函数名：ListNode* removeNthFromEnd(ListNode* head, int n)
* 函数参数：链表的头节点，待删除节点的倒序索引
* 函数返回值：返回节点指针
* 问题描述：
	给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
	说明：

	给定的 n 保证是有效的。

	进阶：

	你能尝试使用一趟扫描实现吗？
* 解决方案：
		1、两个指针，一个probeNode指针用来遍历链表，直到最后一个节点，另一个preDeleteNode始终与探针保持 n+1 的距离
		2、一旦probeNode和preDeleteNode的距离超过 n+1，两个探针同时移动，否则只移动探针
		3、当探针达到最后尾节点时，preDeleteNode刚好指向待删除节点的前一个节点，删除preDeleteNode的下一个节点（即待删除节点）
		
* 测试信息：
	执行用时 :4 ms, 在所有 cpp 提交中击败了95.49%的用户
	内存消耗 :8.5 MB, 在所有 cpp 提交中击败了88.97%的用户
**/
ListNode* CLinkedList::removeNthFromEnd(ListNode* head, int n)
{
	
	ListNode* probeNode = head;  // 探针，遍历整理表
	ListNode* preDeleteNode = head;  // 待删除的节点的前一个节点
	int distance = 1;
	for (; probeNode->next != NULL; ++distance)
	{

		probeNode = probeNode->next;
		if (distance >= n + 1)  // 如果距离超过 n+1 ，即当探针到达尾指针时，preDeleteNode表示的节点刚好是待删除节点的前一个节点
			preDeleteNode = preDeleteNode->next;

	}
	if (distance == n)  // 退出循环后，distance同时又有整个链表长度的意义，当链表长度等于n时，表示删除头结点
	{  // 因为头结点没有前一个节点，所以要特殊处理
		head = head->next;
		return head;
	}
	preDeleteNode->next = preDeleteNode->next->next;
	return head;

	
}
// 失败
ListNode* CLinkedList::reverseList(ListNode* head) {
	ListNode *tempNode = head;
	ListNode* nextNode = tempNode->next;
	ListNode* brigeNode;
	ListNode* reverserHead = head;
	while (nextNode->next != NULL)
	{
		brigeNode = tempNode->next;
		reverserHead->val = nextNode->val;
		reverserHead->next->val = tempNode->val;

		tempNode = tempNode->next;
		nextNode = nextNode->next;
		reverserHead = reverserHead->next;

	}
	return reverserHead;
}