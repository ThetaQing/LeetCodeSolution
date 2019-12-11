#include <iostream>
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
// ʧ��
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