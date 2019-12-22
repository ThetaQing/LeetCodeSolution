#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
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

/********************函数说明******************
* 函数名：ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
* 函数参数：两个有序链表
* 函数返回值：两个有序链表合并之后的有序链表
* 函数实现：
*/
// 失败
ListNode* CLinkedList::mergeTwoLists(ListNode* l1, ListNode* l2) {
		
	ListNode *ans = NULL;
	ListNode* currNode = NULL, *nextNode = NULL, *tempNode = NULL;
	ListNode* p1 = l1, * p2 = l2;

	/*while (p1 != NULL && p2 != NULL)
	{
		if (p1->val < p2->val)
		{
			tempNode = p1->next;
			

		}
		if (p1->val >= p2->val)
		{
			
		}



	}
	if (p1 == NULL && p2 != NULL)
	{
		currNode->next = p2;
	}
	else
		currNode->next = p1;*/

	return l1;


}

/****************函数说明****************
* 函数名：ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
* 函数参数：两个链表
* 函数返回值：如果两个链表相交，返回两个链表相交的第一个节点，否则返回NULL；
* 函数实现：
	 (一) 两层循环……嘤嘤嘤
	（二）利用路程相等
* 测试信息：5%，两层循环，死慢死慢滴



**/

ListNode* CLinkedList::getIntersectionNode(ListNode* headA, ListNode* headB) {
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
ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB)
{
	ListNode* pA = headA;
	ListNode* pB = headB;


	while (pA != pB)
	{
		if (pA == NULL)  // 如果pA走到A链表的尾结点了，转去走B链表
			pA = headB;
		else
			pA = pA->next;

		if (pB == NULL)  // 如果pB走到B链表的尾结点了，转去走A链表
			pB = headA;
		else
			pB = pB->next;

	}
	// 最后相遇的点就是交点
	// A: ——*——
	// B: ———*———
	// pA: ——*——  ———*———  ———*———  ———*———  ———*———  ———*———  ———*———  ———*
	// PB：———*———  ——*——  ——*——  ——*——  ——*——  ——*——  ——*——  ——*——  ——*——  ——*（相遇） 
	return pA;
}

/***************函数说明*****************
* 函数名：ListNode* removeElements(ListNode* head, int val)
* 函数参数：链表的头节点，待删除的节点元素值val
* 函数返回值：返回删除所有val值的节点后的新链表
* 函数实现：
	双指针法：
		currNode表示当前节点，preNode表示currNode的前一个节点
		如果当前节点就是要删除的节点，将当前节点的前一个节点指向当前节点的下一个节点（事先定义变量暂存）nextNode，然后把当前节点变为nextNode，继续遍历；
		如果当前节点不是要删除的节点，移动指针。
		这里需要指出的是对头结点是要删除节点的处理
		（一）先处理头结点，再处理其他，保证链表遍历中要删除的点都有前一个节点。
		（二）创建一个虚拟头结点，保证每一个要删除的节点都有一个前驱。
* 测试信息：
	（一） 
		 32ms， 86.37%
	
	（二）执行用时 :32 ms, 在所有 cpp 提交中击败了86.37%的用户
		  内存消耗 :10.9 MB, 在所有 cpp 提交中击败了88.95%的用户
**/
ListNode* CLinkedList::removeElements(ListNode* head, int val) {

	if (head == NULL)
		return NULL;
	while (head != NULL && head->val == val)  // 如果要删除的是头结点（不存在删除节点的前一个节点）
		head = head->next;
	ListNode* preNode = head;  // 存储要删除节点的前一个节点
	ListNode* currNode = head;
	while (currNode != NULL)
	{		
		if ( currNode->val == val)  // 如果现在这个节点就是要删除的节点
		{
			ListNode* nextNode = currNode->next;
			// 虽然这里没有对preNode显式赋值，但是这里可以保证第一次执行的时候先执行的else语句对preNode赋值（因为第一次删除的不可能是头结点，头结点已经在上一条while语句中全部处理掉了）
			preNode->next = nextNode;  // 把当前节点的前一个节点的指针指向当前节点的下一个节点
			currNode = nextNode;  // 继续遍历
		}
		else
		{
			preNode = currNode;
			currNode = currNode->next;
		}
	}
	return head;


}
ListNode* CLinkedList::removeElements2(ListNode* head, int val) {
	
	if (head == NULL)
		return NULL;
	// 创建一个虚拟头结点
	ListNode dummyNode(val - 1);
	dummyNode.next = head;

	ListNode* preNode = &dummyNode;  // 存储要删除节点的前一个节点
	ListNode* currNode = head;
	while (currNode != NULL)
	{
		if (currNode->val == val)  // 如果现在这个节点就是要删除的节点
		{
			ListNode* nextNode = currNode->next;
			
			preNode->next = nextNode;  // 把当前节点的前一个节点的指针指向当前节点的下一个节点
			currNode = nextNode;  // 继续遍历
		}
		else
		{
			preNode = currNode;
			currNode = currNode->next;
		}
	}
	return dummyNode.next;
}
// 16ms， 94.55%
/******************函数说明******************
* 函数名：ListNode* oddEvenList(ListNode* head)
* 函数参数：一个链表
* 函数返回值：返回一个将原链表的奇数节点和偶数节点重新排列后的链表
* 问题描述：
	给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

	请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/odd-even-linked-list
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

* 解决方案：
		五个变量，分别表示当前奇数节点、当前偶数节点、下一个奇数节点、下一个偶数节点、偶数节点的起始节点
		1、更改指向关系
			将当前奇数节点的下一个节点变为下一个奇数节点：oddNode->next = nextOdd;
			将当前偶数节点的下一个节点变为下一个偶数节点：evenNode->next = nextEven;
			建立奇偶连接，让新的奇数节点的下一个节点是偶数节点的起始节点：nextOdd->next = evenBegin;
		2、更新节点：
			将当前奇数节点变为下一个奇数节点：oddNode = nextOdd;
			当前偶数节点变为下一个偶数节点：evenNode = nextEven;
**/
ListNode* oddEvenList(ListNode* head) {
	

	if (head == NULL || head->next == NULL)
		return head;
	ListNode* oddNode = head, * evenNode = head->next;  // 分别表示当前的奇数节点和偶数节点
	ListNode* nextOdd, * nextEven;  // 分别表示下一个奇数节点和偶数节点
	ListNode* evenBegin = head->next;
	// 不管是奇数还是偶数，只要退出循环就可以返回了
	while (evenNode != NULL && evenNode->next != NULL)
	{
		nextOdd = evenNode->next;  // 保存节点
		nextEven = nextOdd->next;

		oddNode->next = nextOdd;  // 更改指向关系
		evenNode->next = nextEven;

		nextOdd->next = evenBegin;  // 建立奇偶连接

		// 更新节点
		oddNode = nextOdd;
		evenNode = nextEven;
	}
	// 如果 evenNode == NULL，说明当前的偶数节点就是最后一个节点（NULL）
	// 如果 evenNode->next == NULL，说明当前的偶数节点就是尾结点，尾结点后面是NULL
	return head;
}
/*******************函数说明******************
* 函数名：bool isPalindrome(ListNode* head) 
* 函数参数：链表的头结点
* 函数返回值：是否是回文链表，当且仅当链表是回文链表返回true
* 问题描述：234.回文链表：请判断一个链表是否为回文链表。
* 解决方案：
		将前半部分链表翻转，再比较
		1、先求长度len；
		2、再给当前节点、当前节点的前一个节点、当前节点的后一个节点赋值（也就是对特殊情况预先处理）
		3、翻转前一半链表：
			把当前节点currNode的next指针指向前一个节点preNode；
			更新新的currNode、preNode、nextNode
		4、比较翻转后的前一半链表与后一半链表是否一一对应相等
		（注意，如果链表长度是奇数个，currNode还要再移动一个位置）
* 测试信息：24ms，72.67%
**/
bool CLinkedList:: isPalindrome(ListNode* head) {
	
	
	ListNode* currNode = head;
	ListNode* preNode = head;
	ListNode* nextNode = head;
	// 先求长度
	int len = 0;
	while (currNode != NULL)
	{
		currNode = currNode->next;
		len += 1;
	}
	int index = 1;
	currNode = head;
	preNode = currNode;
	if (currNode != NULL && currNode->next != NULL)
	{
		currNode = currNode->next;
		nextNode = currNode->next;
	}
	else  // 链表为空或者只有一个元素
		return 1;

	head->next = NULL;  // 头结点next指针清零，避免循环
	// 翻转前一半
	while (index < len / 2 && currNode != NULL)
	{
		currNode->next = preNode;  // 翻转		
		preNode = currNode;  // 更新新的preNode
		currNode = nextNode;  // 更新新的currNode
		nextNode = currNode->next;  // 更新新的nextNode
		// 三个节点的更新顺序一定是先preNode，再currNode，最后nextNode
		index += 1;
	}
	if (len % 2 && currNode != NULL)  // 如果是奇数个节点，要后移一个节点
		currNode = currNode->next;

	while (currNode != NULL)
	{
		if (currNode->val != preNode->val)  // 如果不相等，不是回文链表
			return 0;
		else  // 否则比较下一对
		{
			currNode = currNode->next;
			preNode = preNode->next;
		}
	}
	return 1;
	

}

/****************函数说明*************
* 函数名：ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
* 函数参数：
* 函数返回值：
* 问题描述：
* 解决方案：
		1、先翻转
		2、再加减
* 测试信息：


**/
ListNode* CLinkedList::addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode* currl1Node = l1, * currl2Node = l2, *preNode = l1;
	// 相加
	ListNode* ans = currl1Node;
	int sum = 0;
	int flag = 0;  // 进位标志
	while (currl1Node != NULL || currl2Node != NULL)  // 如果不是尾结点
	{
		if (currl1Node == NULL && currl2Node != NULL)  // 如果currl1Node到尾结点了
		{
			currl1Node = currl2Node;
			sum = (currl1Node->val + flag) % 10;
			if (currl1Node->val + flag >= 10)
				flag = 1;
			currl1Node->val = sum;
			while (flag&& currl1Node != NULL)
			{
				currl1Node = currl1Node->next;
				sum = (currl1Node->val + flag) % 10;
				if (currl1Node->val + flag >= 10)
					flag = 1;
				currl1Node->val = sum;
			}
			if (flag)
				break;
			else
				return ans;
			
		}
		else if (currl2Node == NULL && currl1Node != NULL)  // 如果currl2Node到尾结点了
		{
			sum = (currl1Node->val + flag) % 10;
			if (currl1Node->val + flag >= 10)
				flag = 1;
			currl1Node->val = sum;
			while (flag && currl1Node != NULL)
			{
				currl1Node = currl1Node->next;
				sum = (currl1Node->val + flag) % 10;
				if (currl1Node->val + flag >= 10)
					flag = 1;
				currl1Node->val = sum;
			}
			if (flag)
				break;
			else
				return ans;
			
		}
		
		else
		{
			sum = (currl1Node->val + currl2Node->val + flag) % 10;  // 对两个节点求和

			if (currl1Node->val + currl2Node->val >= 10)  // 进位标志
				flag = 1;
			else
				flag = 0;

			currl1Node->val = sum;  // 更新节点值
			// 更新节点
			preNode = currl1Node;
			currl1Node = currl1Node->next;
			currl2Node = currl2Node->next;
		}
		
	}
	ListNode  *temp = NULL;
	
	if (l2 != NULL)
	{
		temp = l2;
		temp->val = flag;
		l2->next = NULL;
	}
	if (flag && preNode != NULL)
	{
		preNode->next = temp;
	}
	
	return ans;
}

/*****************函数说明*************
* 修改信息：
* 实现思路：
		几点说明：链表1是最后返回的链表，链表2是最后处理进位的链表，当节点为空但是运算没有结束的时候给空节点赋0值
		1、如果两个当前节点均不为空，正常操作，这个是最简单的
		2、如果链表1比链表2长，这个也比较简单，就把链表2的其他部分始终赋0值；
		3、如果链表1比链表2短，交换两个指针的指向，也就是把链表2长的那部分链接到链表1后面，然后把链表2的当前指针赋NULL
* 测试信息： 32ms， 57.22%


**/
ListNode* CLinkedList::addTwoNumbers2(ListNode* l1, ListNode* l2)
{
	ListNode* currl1Node = l1, * currl2Node = l2, * preNode = l1;
	ListNode* ans = currl1Node;
	ListNode* temp;
	
	ListNode* flagnode = l2;
	// 相加
	
	int sum = 0;
	int currl1 = 0, currl2 = 0;  // 分别表示链表1、2当前节点的值
	int flag = 0;  // 进位标志
	while (currl1Node != NULL || currl2Node != NULL)  // 两个节点都有值
	{
		if (currl1Node != NULL)
			currl1 = currl1Node->val;
		else if(currl2Node != NULL && preNode != NULL)
		{
			temp = currl2Node->next;  // 先保存链表2当前节点的下一个节点
			currl1Node = currl2Node;			// 再把链表2的当前节点保存到链表1的当前节点，即两个指针现在指向链表2的同一个位置
			preNode->next = currl1Node;  // 建立链表1与currl1Node（原链表1的当前节点），一定要有，否则，链表1是没有发生变化的，那么此时currl2Node就变成了链表1的尾结点
			currl1Node->next = temp;  // 把此时链表1的尾结点的next指向之前保存下来的链表2的下一个节点
			currl1 = currl1Node->val;  // 取值
			currl2Node = NULL;  // 始终赋空
		}

		if (currl2Node != NULL)
			currl2 = currl2Node->val;
		else
			currl2 = 0;
		sum = (currl1 + currl2 + flag);  // 对两个节点求和
		if (sum >= 10)  // 进位标志
			flag = 1;
		else
			flag = 0;
		if(currl1Node != NULL)
			currl1Node->val = sum % 10;  // 插入节点
		
		// 更新节点
		preNode = currl1Node;
		if (currl1Node != NULL)
			currl1Node = currl1Node->next;
		if(currl2Node != NULL)
			currl2Node = currl2Node->next;
	}
	if (flag && preNode != NULL)
	{
		flagnode->val = 1;
		flagnode->next = NULL;
		
		preNode->next = flagnode;
	}
	
	return ans;
	
}
/***************函数说明**************
* 函数名：Node* flatten(Node* head)
* 函数参数：一个多级链表的头指针
* 函数返回值：拉直后的链表头指针
* 问题描述：
	430. 扁平化多级双向链表
	您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

	扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
* 解决方案：
		1、遍历第一级链表的所有节点
			(1) 把该节点开始的所有子链表拉直
			(2) 把该节点开始的所有子链表的尾结点与上一级链表相连接
		2、更新第一级链表新的遍历节点

		详细说明下第一步的两个小步：
		拉直操作：
		(1) 如果该节点的子指针不为空，说明有子链表，保存这个节点的next节点到栈中（因为栈是后进先出）
		(2) 把该节点的子节点并入到该节点这一级链表中，即该节点的next指向子节点，子节点的pre指向当前节点，该节点子指针赋空，完成并入操作；
		(3) 移动当前节点，重复(1)(2)直到完成第一级这个节点下的所有子链表的拉直操作，判断标准就是当前节点为空，此时不存在next节点后还有子链表的可能。
		
		完成拉直后就是利用栈的后进先出做连接，主要是将一个
		(4) 先取出最近的上一级的next节点，将当期节点的前驱节点与上一级的next节点建立连接
		(5) 寻找子链表的下一个空节点继续连接

		对第一级的
* 测试信息：8ms， 96.22%

**/
Node* CLinkedList:: flatten(Node* head) {
	Node* preNode, * currNode, *nextNode, *childNode;
	stack<Node*> nextNodeStack;
	if (head == NULL)  // 节点为空
		return head;

	preNode = head;
	currNode = head;
	while (currNode != NULL)  // 只访问到currNode->next，只需要保证currNode != NULL
	{
		while (currNode != NULL)  // 该节点不是空节点的时候
		{
			while (currNode->child != NULL)  // 判断是都有子指针，如果有，追溯到最底层的节点
			{
				nextNode = currNode->next;  // 记录有子指针的这个节点的下一个节点
				nextNodeStack.push(nextNode);  // 并存入栈中
								
				childNode = currNode->child;  // 暂存子节点
				currNode->next = childNode;  // 当前节点的下一个节点变为它的子节点
				childNode->prev = currNode;  // 子节点的前一个节点是当前节点
				currNode->child = NULL;  // 当前节点的子节点设置为空
				currNode = currNode->next;
			}
			
			preNode = currNode;
			currNode = currNode->next;
		}
		// 退出之后由第一级链表最开始的当前节点开始的所有的子节点都被拉直
		while (!nextNodeStack.empty() && currNode == NULL)
		{
			nextNode = nextNodeStack.top();  // 提取最近的上一级
			nextNodeStack.pop();

			preNode->next = nextNode;
			currNode = nextNode;
			if (currNode != NULL)  // 如果该节点不是空节点，建立前驱连接
			{
				currNode->prev = preNode;  // 建立前驱连接
				
			}
			while (currNode != NULL)  // 寻找下一个空节点（因为空节点就意味着这一条子链表走完了，可以对上一级建立连接）
			{
				preNode = currNode;  // 前一个节点的追踪，因为建立连接时，currNode是空指针
				currNode = currNode->next;
			}
					
		}
		// 退出之后所有以第一级链表的当前节点开始的所有子节点全部和当前节点的下一个节点顺利连接
		if (currNode != NULL)  // 开始第一级链表的下一个节点
		{
			preNode = currNode;
			currNode = currNode->next;
		}
		
	}		
	return head;
}
// 空间迭代
NodeWithRandom* copyRandomList(NodeWithRandom* head) {

	NodeWithRandom* currNode = head, * randomNode = head, * nextNode = head;
	NodeWithRandom* copyNodeHead = head, *copyNode = head;
	if (head == NULL)
	{
		NodeWithRandom* newNode = NULL;
		return newNode;
	}

	// 第一步，拷贝节点到每个节点的下一个节点位置
	while (currNode != NULL)
	{
		NodeWithRandom* newNode = new NodeWithRandom(currNode->val);  // 构建一个节点，该节点的值是当前节点的值，random指针为空
		nextNode = currNode->next;
		currNode->next = newNode;
		newNode->next = nextNode;  // 把新节点插入到当前节点的后面

		currNode = nextNode;  // 更新当前节点
	}

	// 第二步，建立新节点之间的random指针关系
	currNode = head;
	while (currNode != NULL && currNode->next != NULL)
	{
		nextNode = currNode->next;
		randomNode = currNode->random;

		// 新节点始终在原节点的后面，所以如果原节点的random指针存在，那么新节点的random指针就应该指向原节点的random指针的下一个节点
		nextNode->random = randomNode == NULL ? NULL : randomNode->next;
		// 更新节点
		currNode = nextNode->next;
	}
	 // 第三步，拆分链表
	currNode = head;
	if(currNode != NULL)
		copyNodeHead = currNode->next;	
	NodeWithRandom* nextCopyNode;
	while (currNode != NULL  && currNode->next != NULL && currNode->next->next != NULL)
	{
		// 暂存节点
		copyNode = currNode->next;
		nextNode = copyNode->next;
		nextCopyNode = nextNode->next;
		// 建立新的链接
		currNode->next = nextNode;
		copyNode->next = nextCopyNode;

		// 更新节点
		currNode = nextNode;
		

	}
	// 退出之后还有最后两个节点
	currNode->next = NULL;

	return copyNodeHead;


}

