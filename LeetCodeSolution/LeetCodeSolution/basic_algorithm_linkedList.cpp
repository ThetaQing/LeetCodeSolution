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
