#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
/***************函数说明***************
* 函数名：
* 函数参数：
* 函数返回值：
* 问题描述：
	反转一个单链表。

	示例:

	输入: 1->2->3->4->5->NULL
	输出: 5->4->3->2->1->NULL
	进阶:
	你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/reverse-linked-list
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
* 解决方案：
	一、迭代（官网）
		在遍历列表时，将当前节点的next指针改为指向前一个元素，由于节点没有引用其上一个节点，因此必须事先先存储其前一个元素。
		在更改引用之前，还需要另一个指针来存储下一个节点，不要忘记在最后返回新的头引用。
	二、迭代（自己复现）
* 测试信息：
	12ms, 67.79%

**/
ListNode* CLinkedList::reverseList(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* curr = head;
	while (curr != NULL)
	{
		ListNode* nextTemp = curr->next;  
		curr->next = prev;
		prev = curr;
		curr = nextTemp;

	}
	return prev;

}

/******************************
* 修改说明：
* 测试信息：
	执行用时 :8 ms, 在所有 cpp 提交中击败了96.00%的用户
	内存消耗 :9 MB, 在所有 cpp 提交中击败了83.31%的用户
**/
ListNode* CLinkedList::reverseList2(ListNode* head) {
	ListNode* tempNode = head;
	ListNode* brigeNode;
	ListNode* reverserHead = NULL;
	while (tempNode != NULL)
	{
		brigeNode = tempNode->next;  // 保留下一个节点的指针
		
		tempNode->next = reverserHead;   // 把这个节点的next指向翻转后链表的头指针

		reverserHead = tempNode;  // 更新头指针

		tempNode = brigeNode;   // 更新用于遍历原链表的指针

		

	}
	return reverserHead;  // 返回头指针
}

// 递归 失败
/*
ListNode* CLinkedList::reverseList3(ListNode* head) {
	
	ListNode* endHead = NULL, * tempNode = NULL;
	ListNode* ansNode;  // 存储返回的节点
	ListNode* nextNode;  // 存储head的下一个节点
	if (head->next != NULL)
	{
		ansNode = reverseList3(head->next);
		ansNode->next = endHead;
		endHead = ansNode;
		head->next = NULL;
	}
	else 
	{
		ListNode* ans = head;
		head = NULL;
		return ans;
	}
	return endHead;

}
*/
ListNode* CLinkedList::reverseList3(ListNode* head) {

	if (head == NULL || head->next == NULL)
		return head;
	ListNode* p = reverseList3(head->next);
	head->next->next = head;
	head->next = NULL;  // 防止链表循环
	return p;

}

/***************************************/

ListNode* CLinkedList::mergeTwoLists(ListNode* l1, ListNode* l2) {
	
	
	/*
	
	ListNode ans(-1);
	ListNode* temp;
	ListNode* p1 = l1, * p2 = l2;
	temp = &ans;
	while (p1->next != NULL && p2->next != NULL)
	{
		if (p1->val < p2->val)

		{
			temp->next = p1;

			p1 = p1->next;
			temp = temp->next;
			//p1->val = p1->next->val;
			//p1->next = p1->next->next;

		}
		if (p1->val >= p2->val)
		{
			temp->next = p2;
			//p2->val = p2->next->val;
			//p2->next = p2->next->next;
			p2 = p2->next;
			temp = temp->next;
		}



	}
	if (p1->next == NULL && p2->next != NULL)
	{
		temp->next = p2;
	}
	else
		temp->next = p1;

	return temp->next;*/


}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	ListNode* pA = headA;
	ListNode* pB = headB;
	// 
	if (pA == NULL || pB == NULL)
		return NULL;
	
	while (pA != NULL )
	{
		pB = headB;
		while(pB != NULL)
			if (pA != pB)
			{				
				pB = pB->next;
			}
			else
				return pA;
		pA = pA->next;
	}
	return NULL;
}
