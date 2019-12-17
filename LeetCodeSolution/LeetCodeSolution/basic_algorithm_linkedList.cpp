#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "basic_algorithm_linkedList.h"
using namespace std;


/***************�ļ�˵��*************
* �ļ�����basic_algorithm_linkedList.cpp
* �ļ����ܣ�LeetCode�����㷨������

**/
/***************����˵��*************
* ��������ListNode* removeNthFromEnd(ListNode* head, int n)
* ���������������ͷ�ڵ㣬��ɾ���ڵ�ĵ�������
* ��������ֵ�����ؽڵ�ָ��
* ����������
	����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
	˵����

	������ n ��֤����Ч�ġ�

	���ף�

	���ܳ���ʹ��һ��ɨ��ʵ����
* ���������
		1������ָ�룬һ��probeNodeָ��������������ֱ�����һ���ڵ㣬��һ��preDeleteNodeʼ����̽�뱣�� n+1 �ľ���
		2��һ��probeNode��preDeleteNode�ľ��볬�� n+1������̽��ͬʱ�ƶ�������ֻ�ƶ�̽��
		3����̽��ﵽ���β�ڵ�ʱ��preDeleteNode�պ�ָ���ɾ���ڵ��ǰһ���ڵ㣬ɾ��preDeleteNode����һ���ڵ㣨����ɾ���ڵ㣩
		
* ������Ϣ��
	ִ����ʱ :4 ms, ������ cpp �ύ�л�����95.49%���û�
	�ڴ����� :8.5 MB, ������ cpp �ύ�л�����88.97%���û�
**/
ListNode* CLinkedList::removeNthFromEnd(ListNode* head, int n)
{
	
	ListNode* probeNode = head;  // ̽�룬���������
	ListNode* preDeleteNode = head;  // ��ɾ���Ľڵ��ǰһ���ڵ�
	int distance = 1;
	for (; probeNode->next != NULL; ++distance)
	{

		probeNode = probeNode->next;
		if (distance >= n + 1)  // ������볬�� n+1 ������̽�뵽��βָ��ʱ��preDeleteNode��ʾ�Ľڵ�պ��Ǵ�ɾ���ڵ��ǰһ���ڵ�
			preDeleteNode = preDeleteNode->next;

	}
	if (distance == n)  // �˳�ѭ����distanceͬʱ�������������ȵ����壬�������ȵ���nʱ����ʾɾ��ͷ���
	{  // ��Ϊͷ���û��ǰһ���ڵ㣬����Ҫ���⴦��
		head = head->next;
		return head;
	}
	preDeleteNode->next = preDeleteNode->next->next;
	return head;

	
}
/***************����˵��***************
* ��������
* ����������
* ��������ֵ��
* ����������
	��תһ��������

	ʾ��:

	����: 1->2->3->4->5->NULL
	���: 5->4->3->2->1->NULL
	����:
	����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/reverse-linked-list
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
* ���������
	һ��������������
		�ڱ����б�ʱ������ǰ�ڵ��nextָ���Ϊָ��ǰһ��Ԫ�أ����ڽڵ�û����������һ���ڵ㣬��˱��������ȴ洢��ǰһ��Ԫ�ء�
		�ڸ�������֮ǰ������Ҫ��һ��ָ�����洢��һ���ڵ㣬��Ҫ��������󷵻��µ�ͷ���á�
	�����������Լ����֣�
* ������Ϣ��
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
* �޸�˵����
* ������Ϣ��
	ִ����ʱ :8 ms, ������ cpp �ύ�л�����96.00%���û�
	�ڴ����� :9 MB, ������ cpp �ύ�л�����83.31%���û�
**/
ListNode* CLinkedList::reverseList2(ListNode* head) {
	ListNode* tempNode = head;
	ListNode* brigeNode;
	ListNode* reverserHead = NULL;
	while (tempNode != NULL)
	{
		brigeNode = tempNode->next;  // ������һ���ڵ��ָ��
		
		tempNode->next = reverserHead;   // ������ڵ��nextָ��ת�������ͷָ��

		reverserHead = tempNode;  // ����ͷָ��

		tempNode = brigeNode;   // �������ڱ���ԭ�����ָ��

		

	}
	return reverserHead;  // ����ͷָ��
}

// �ݹ� ʧ��
/*
ListNode* CLinkedList::reverseList3(ListNode* head) {
	
	ListNode* endHead = NULL, * tempNode = NULL;
	ListNode* ansNode;  // �洢���صĽڵ�
	ListNode* nextNode;  // �洢head����һ���ڵ�
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
	head->next = NULL;  // ��ֹ����ѭ��
	return p;

}

/********************����˵��******************
* ��������ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
* ����������������������
* ��������ֵ��������������ϲ�֮�����������
* ����ʵ�֣�
*/
// ʧ��
ListNode* CLinkedList::mergeTwoLists(ListNode* l1, ListNode* l2) {
		
	ListNode *ans;
	ListNode* currNode, *nextNode, *tempNode;
	ListNode* p1 = l1, * p2 = l2;

	while (p1 != NULL && p2 != NULL)
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
		currNode->next = p1;

	return currNode->next;


}

/****************����˵��****************
* ��������ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
* ������������������
* ��������ֵ��������������ཻ���������������ཻ�ĵ�һ���ڵ㣬���򷵻�NULL��
* ����ʵ�֣�
	 (һ) ����ѭ������������
	����������·�����
* ������Ϣ��5%������ѭ��������������



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
		if (pA == NULL)  // ���pA�ߵ�A�����β����ˣ�תȥ��B����
			pA = headB;
		else
			pA = pA->next;

		if (pB == NULL)  // ���pB�ߵ�B�����β����ˣ�תȥ��A����
			pB = headA;
		else
			pB = pB->next;

	}
	// ��������ĵ���ǽ���
	// A: ����*����
	// B: ������*������
	// pA: ����*����  ������*������  ������*������  ������*������  ������*������  ������*������  ������*������  ������*
	// PB��������*������  ����*����  ����*����  ����*����  ����*����  ����*����  ����*����  ����*����  ����*����  ����*�������� 
	return pA;
}

/***************����˵��*****************
* ��������ListNode* removeElements(ListNode* head, int val)
* ���������������ͷ�ڵ㣬��ɾ���Ľڵ�Ԫ��ֵval
* ��������ֵ������ɾ������valֵ�Ľڵ���������
* ����ʵ�֣�
	˫ָ�뷨��
		currNode��ʾ��ǰ�ڵ㣬preNode��ʾcurrNode��ǰһ���ڵ�
		�����ǰ�ڵ����Ҫɾ���Ľڵ㣬����ǰ�ڵ��ǰһ���ڵ�ָ��ǰ�ڵ����һ���ڵ㣨���ȶ�������ݴ棩nextNode��Ȼ��ѵ�ǰ�ڵ��ΪnextNode������������
		�����ǰ�ڵ㲻��Ҫɾ���Ľڵ㣬�ƶ�ָ�롣
		������Ҫָ�����Ƕ�ͷ�����Ҫɾ���ڵ�Ĵ���
		��һ���ȴ���ͷ��㣬�ٴ�����������֤���������Ҫɾ���ĵ㶼��ǰһ���ڵ㡣
		����������һ������ͷ��㣬��֤ÿһ��Ҫɾ���Ľڵ㶼��һ��ǰ����
* ������Ϣ��
	��һ�� 
		 32ms�� 86.37%
	
	������ִ����ʱ :32 ms, ������ cpp �ύ�л�����86.37%���û�
		  �ڴ����� :10.9 MB, ������ cpp �ύ�л�����88.95%���û�
**/
ListNode* CLinkedList::removeElements(ListNode* head, int val) {

	if (head == NULL)
		return NULL;
	while (head != NULL && head->val == val)  // ���Ҫɾ������ͷ��㣨������ɾ���ڵ��ǰһ���ڵ㣩
		head = head->next;
	ListNode* preNode = head;  // �洢Ҫɾ���ڵ��ǰһ���ڵ�
	ListNode* currNode = head;
	while (currNode != NULL)
	{		
		if ( currNode->val == val)  // �����������ڵ����Ҫɾ���Ľڵ�
		{
			ListNode* nextNode = currNode->next;
			// ��Ȼ����û�ж�preNode��ʽ��ֵ������������Ա�֤��һ��ִ�е�ʱ����ִ�е�else����preNode��ֵ����Ϊ��һ��ɾ���Ĳ�������ͷ��㣬ͷ����Ѿ�����һ��while�����ȫ��������ˣ�
			preNode->next = nextNode;  // �ѵ�ǰ�ڵ��ǰһ���ڵ��ָ��ָ��ǰ�ڵ����һ���ڵ�
			currNode = nextNode;  // ��������
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
	// ����һ������ͷ���
	ListNode dummyNode(val - 1);
	dummyNode.next = head;

	ListNode* preNode = &dummyNode;  // �洢Ҫɾ���ڵ��ǰһ���ڵ�
	ListNode* currNode = head;
	while (currNode != NULL)
	{
		if (currNode->val == val)  // �����������ڵ����Ҫɾ���Ľڵ�
		{
			ListNode* nextNode = currNode->next;
			
			preNode->next = nextNode;  // �ѵ�ǰ�ڵ��ǰһ���ڵ��ָ��ָ��ǰ�ڵ����һ���ڵ�
			currNode = nextNode;  // ��������
		}
		else
		{
			preNode = currNode;
			currNode = currNode->next;
		}
	}
	return dummyNode.next;
}
// 16ms�� 94.55%
/******************����˵��******************
* ��������ListNode* oddEvenList(ListNode* head)
* ����������һ������
* ��������ֵ������һ����ԭ����������ڵ��ż���ڵ��������к������
* ����������
	����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�

	�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/odd-even-linked-list
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

* ���������
		����������ֱ��ʾ��ǰ�����ڵ㡢��ǰż���ڵ㡢��һ�������ڵ㡢��һ��ż���ڵ㡢ż���ڵ����ʼ�ڵ�
		1������ָ���ϵ
			����ǰ�����ڵ����һ���ڵ��Ϊ��һ�������ڵ㣺oddNode->next = nextOdd;
			����ǰż���ڵ����һ���ڵ��Ϊ��һ��ż���ڵ㣺evenNode->next = nextEven;
			������ż���ӣ����µ������ڵ����һ���ڵ���ż���ڵ����ʼ�ڵ㣺nextOdd->next = evenBegin;
		2�����½ڵ㣺
			����ǰ�����ڵ��Ϊ��һ�������ڵ㣺oddNode = nextOdd;
			��ǰż���ڵ��Ϊ��һ��ż���ڵ㣺evenNode = nextEven;
**/
ListNode* oddEvenList(ListNode* head) {
	

	if (head == NULL || head->next == NULL)
		return head;
	ListNode* oddNode = head, * evenNode = head->next;  // �ֱ��ʾ��ǰ�������ڵ��ż���ڵ�
	ListNode* nextOdd, * nextEven;  // �ֱ��ʾ��һ�������ڵ��ż���ڵ�
	ListNode* evenBegin = head->next;
	// ��������������ż����ֻҪ�˳�ѭ���Ϳ��Է�����
	while (evenNode != NULL && evenNode->next != NULL)
	{
		nextOdd = evenNode->next;  // ����ڵ�
		nextEven = nextOdd->next;

		oddNode->next = nextOdd;  // ����ָ���ϵ
		evenNode->next = nextEven;

		nextOdd->next = evenBegin;  // ������ż����

		// ���½ڵ�
		oddNode = nextOdd;
		evenNode = nextEven;
	}
	// ��� evenNode == NULL��˵����ǰ��ż���ڵ�������һ���ڵ㣨NULL��
	// ��� evenNode->next == NULL��˵����ǰ��ż���ڵ����β��㣬β��������NULL
	return head;
}

bool isPalindrome(ListNode* head) {
	
	
	ListNode* currNode = head;
	ListNode* preNode = head;
	
	while (currNode != NULL && head != NULL)
	{
		preNode = currNode;
		
		
		if (currNode->next == NULL)  // ��ʱ��ǰ�ڵ���β���
		{
			if (currNode->val == head->val)  // ����ǻ�������β����ֵ����ͷ����ֵ
			{
				head = head->next;				
				currNode = preNode;
			}
			else
				return 0;
		}
		else
		{
			currNode = currNode->next;
		}
	}
}

