#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
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
/*******************����˵��******************
* ��������bool isPalindrome(ListNode* head) 
* ���������������ͷ���
* ��������ֵ���Ƿ��ǻ����������ҽ��������ǻ���������true
* ����������234.�����������ж�һ�������Ƿ�Ϊ��������
* ���������
		��ǰ�벿������ת���ٱȽ�
		1�����󳤶�len��
		2���ٸ���ǰ�ڵ㡢��ǰ�ڵ��ǰһ���ڵ㡢��ǰ�ڵ�ĺ�һ���ڵ㸳ֵ��Ҳ���Ƕ��������Ԥ�ȴ���
		3����תǰһ������
			�ѵ�ǰ�ڵ�currNode��nextָ��ָ��ǰһ���ڵ�preNode��
			�����µ�currNode��preNode��nextNode
		4���ȽϷ�ת���ǰһ���������һ�������Ƿ�һһ��Ӧ���
		��ע�⣬�������������������currNode��Ҫ���ƶ�һ��λ�ã�
* ������Ϣ��24ms��72.67%
**/
bool CLinkedList:: isPalindrome(ListNode* head) {
	
	
	ListNode* currNode = head;
	ListNode* preNode = head;
	ListNode* nextNode = head;
	// ���󳤶�
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
	else  // ����Ϊ�ջ���ֻ��һ��Ԫ��
		return 1;

	head->next = NULL;  // ͷ���nextָ�����㣬����ѭ��
	// ��תǰһ��
	while (index < len / 2 && currNode != NULL)
	{
		currNode->next = preNode;  // ��ת		
		preNode = currNode;  // �����µ�preNode
		currNode = nextNode;  // �����µ�currNode
		nextNode = currNode->next;  // �����µ�nextNode
		// �����ڵ�ĸ���˳��һ������preNode����currNode�����nextNode
		index += 1;
	}
	if (len % 2 && currNode != NULL)  // ������������ڵ㣬Ҫ����һ���ڵ�
		currNode = currNode->next;

	while (currNode != NULL)
	{
		if (currNode->val != preNode->val)  // �������ȣ����ǻ�������
			return 0;
		else  // ����Ƚ���һ��
		{
			currNode = currNode->next;
			preNode = preNode->next;
		}
	}
	return 1;
	

}

/****************����˵��*************
* ��������ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
* ����������
* ��������ֵ��
* ����������
* ���������
		1���ȷ�ת
		2���ټӼ�
* ������Ϣ��


**/
ListNode* CLinkedList::addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode* currl1Node = l1, * currl2Node = l2, *preNode = l1;
	// ���
	ListNode* ans = currl1Node;
	int sum = 0;
	int flag = 0;  // ��λ��־
	while (currl1Node != NULL || currl2Node != NULL)  // �������β���
	{
		if (currl1Node == NULL && currl2Node != NULL)  // ���currl1Node��β�����
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
		else if (currl2Node == NULL && currl1Node != NULL)  // ���currl2Node��β�����
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
			sum = (currl1Node->val + currl2Node->val + flag) % 10;  // �������ڵ����

			if (currl1Node->val + currl2Node->val >= 10)  // ��λ��־
				flag = 1;
			else
				flag = 0;

			currl1Node->val = sum;  // ���½ڵ�ֵ
			// ���½ڵ�
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

/*****************����˵��*************
* �޸���Ϣ��
* ʵ��˼·��
		����˵��������1����󷵻ص���������2��������λ���������ڵ�Ϊ�յ�������û�н�����ʱ����սڵ㸳0ֵ
		1�����������ǰ�ڵ����Ϊ�գ������������������򵥵�
		2���������1������2�������Ҳ�Ƚϼ򵥣��Ͱ�����2����������ʼ�ո�0ֵ��
		3���������1������2�̣���������ָ���ָ��Ҳ���ǰ�����2�����ǲ������ӵ�����1���棬Ȼ�������2�ĵ�ǰָ�븳NULL
* ������Ϣ�� 32ms�� 57.22%


**/
ListNode* CLinkedList::addTwoNumbers2(ListNode* l1, ListNode* l2)
{
	ListNode* currl1Node = l1, * currl2Node = l2, * preNode = l1;
	ListNode* ans = currl1Node;
	ListNode* temp;
	
	ListNode* flagnode = l2;
	// ���
	
	int sum = 0;
	int currl1 = 0, currl2 = 0;  // �ֱ��ʾ����1��2��ǰ�ڵ��ֵ
	int flag = 0;  // ��λ��־
	while (currl1Node != NULL || currl2Node != NULL)  // �����ڵ㶼��ֵ
	{
		if (currl1Node != NULL)
			currl1 = currl1Node->val;
		else if(currl2Node != NULL && preNode != NULL)
		{
			temp = currl2Node->next;  // �ȱ�������2��ǰ�ڵ����һ���ڵ�
			currl1Node = currl2Node;			// �ٰ�����2�ĵ�ǰ�ڵ㱣�浽����1�ĵ�ǰ�ڵ㣬������ָ������ָ������2��ͬһ��λ��
			preNode->next = currl1Node;  // ��������1��currl1Node��ԭ����1�ĵ�ǰ�ڵ㣩��һ��Ҫ�У���������1��û�з����仯�ģ���ô��ʱcurrl2Node�ͱ��������1��β���
			currl1Node->next = temp;  // �Ѵ�ʱ����1��β����nextָ��֮ǰ��������������2����һ���ڵ�
			currl1 = currl1Node->val;  // ȡֵ
			currl2Node = NULL;  // ʼ�ո���
		}

		if (currl2Node != NULL)
			currl2 = currl2Node->val;
		else
			currl2 = 0;
		sum = (currl1 + currl2 + flag);  // �������ڵ����
		if (sum >= 10)  // ��λ��־
			flag = 1;
		else
			flag = 0;
		if(currl1Node != NULL)
			currl1Node->val = sum % 10;  // ����ڵ�
		
		// ���½ڵ�
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
/***************����˵��**************
* ��������Node* flatten(Node* head)
* ����������һ���༶�����ͷָ��
* ��������ֵ����ֱ�������ͷָ��
* ����������
	430. ��ƽ���༶˫������
	�������һ��˫������������һ����ǰһ��ָ��֮�⣬������һ����ָ�룬����ָ�򵥶���˫��������Щ���б������һ�������Լ�������������ƣ����ɶ༶���ݽṹ���������ʾ����ʾ��

	��ƽ���б�ʹ���н������ڵ���˫�����С���������б��һ����ͷ����

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
* ���������
		1��������һ����������нڵ�
			(1) �Ѹýڵ㿪ʼ��������������ֱ
			(2) �Ѹýڵ㿪ʼ�������������β�������һ������������
		2�����µ�һ�������µı����ڵ�

		��ϸ˵���µ�һ��������С����
		��ֱ������
		(1) ����ýڵ����ָ�벻Ϊ�գ�˵������������������ڵ��next�ڵ㵽ջ�У���Ϊջ�Ǻ���ȳ���
		(2) �Ѹýڵ���ӽڵ㲢�뵽�ýڵ���һ�������У����ýڵ��nextָ���ӽڵ㣬�ӽڵ��preָ��ǰ�ڵ㣬�ýڵ���ָ�븳�գ���ɲ��������
		(3) �ƶ���ǰ�ڵ㣬�ظ�(1)(2)ֱ����ɵ�һ������ڵ��µ��������������ֱ�������жϱ�׼���ǵ�ǰ�ڵ�Ϊ�գ���ʱ������next�ڵ����������Ŀ��ܡ�
		
		�����ֱ���������ջ�ĺ���ȳ������ӣ���Ҫ�ǽ�һ��
		(4) ��ȡ���������һ����next�ڵ㣬�����ڽڵ��ǰ���ڵ�����һ����next�ڵ㽨������
		(5) Ѱ�����������һ���սڵ��������

		�Ե�һ����
* ������Ϣ��8ms�� 96.22%

**/
Node* CLinkedList:: flatten(Node* head) {
	Node* preNode, * currNode, *nextNode, *childNode;
	stack<Node*> nextNodeStack;
	if (head == NULL)  // �ڵ�Ϊ��
		return head;

	preNode = head;
	currNode = head;
	while (currNode != NULL)  // ֻ���ʵ�currNode->next��ֻ��Ҫ��֤currNode != NULL
	{
		while (currNode != NULL)  // �ýڵ㲻�ǿսڵ��ʱ��
		{
			while (currNode->child != NULL)  // �ж��Ƕ�����ָ�룬����У�׷�ݵ���ײ�Ľڵ�
			{
				nextNode = currNode->next;  // ��¼����ָ�������ڵ����һ���ڵ�
				nextNodeStack.push(nextNode);  // ������ջ��
								
				childNode = currNode->child;  // �ݴ��ӽڵ�
				currNode->next = childNode;  // ��ǰ�ڵ����һ���ڵ��Ϊ�����ӽڵ�
				childNode->prev = currNode;  // �ӽڵ��ǰһ���ڵ��ǵ�ǰ�ڵ�
				currNode->child = NULL;  // ��ǰ�ڵ���ӽڵ�����Ϊ��
				currNode = currNode->next;
			}
			
			preNode = currNode;
			currNode = currNode->next;
		}
		// �˳�֮���ɵ�һ�������ʼ�ĵ�ǰ�ڵ㿪ʼ�����е��ӽڵ㶼����ֱ
		while (!nextNodeStack.empty() && currNode == NULL)
		{
			nextNode = nextNodeStack.top();  // ��ȡ�������һ��
			nextNodeStack.pop();

			preNode->next = nextNode;
			currNode = nextNode;
			if (currNode != NULL)  // ����ýڵ㲻�ǿսڵ㣬����ǰ������
			{
				currNode->prev = preNode;  // ����ǰ������
				
			}
			while (currNode != NULL)  // Ѱ����һ���սڵ㣨��Ϊ�սڵ����ζ����һ�������������ˣ����Զ���һ���������ӣ�
			{
				preNode = currNode;  // ǰһ���ڵ��׷�٣���Ϊ��������ʱ��currNode�ǿ�ָ��
				currNode = currNode->next;
			}
					
		}
		// �˳�֮�������Ե�һ������ĵ�ǰ�ڵ㿪ʼ�������ӽڵ�ȫ���͵�ǰ�ڵ����һ���ڵ�˳������
		if (currNode != NULL)  // ��ʼ��һ���������һ���ڵ�
		{
			preNode = currNode;
			currNode = currNode->next;
		}
		
	}		
	return head;
}
// �ռ����
NodeWithRandom* copyRandomList(NodeWithRandom* head) {

	NodeWithRandom* currNode = head, * randomNode = head, * nextNode = head;
	NodeWithRandom* copyNodeHead = head, *copyNode = head;
	if (head == NULL)
	{
		NodeWithRandom* newNode = NULL;
		return newNode;
	}

	// ��һ���������ڵ㵽ÿ���ڵ����һ���ڵ�λ��
	while (currNode != NULL)
	{
		NodeWithRandom* newNode = new NodeWithRandom(currNode->val);  // ����һ���ڵ㣬�ýڵ��ֵ�ǵ�ǰ�ڵ��ֵ��randomָ��Ϊ��
		nextNode = currNode->next;
		currNode->next = newNode;
		newNode->next = nextNode;  // ���½ڵ���뵽��ǰ�ڵ�ĺ���

		currNode = nextNode;  // ���µ�ǰ�ڵ�
	}

	// �ڶ����������½ڵ�֮���randomָ���ϵ
	currNode = head;
	while (currNode != NULL && currNode->next != NULL)
	{
		nextNode = currNode->next;
		randomNode = currNode->random;

		// �½ڵ�ʼ����ԭ�ڵ�ĺ��棬�������ԭ�ڵ��randomָ����ڣ���ô�½ڵ��randomָ���Ӧ��ָ��ԭ�ڵ��randomָ�����һ���ڵ�
		nextNode->random = randomNode == NULL ? NULL : randomNode->next;
		// ���½ڵ�
		currNode = nextNode->next;
	}
	 // ���������������
	currNode = head;
	if(currNode != NULL)
		copyNodeHead = currNode->next;	
	NodeWithRandom* nextCopyNode;
	while (currNode != NULL  && currNode->next != NULL && currNode->next->next != NULL)
	{
		// �ݴ�ڵ�
		copyNode = currNode->next;
		nextNode = copyNode->next;
		nextCopyNode = nextNode->next;
		// �����µ�����
		currNode->next = nextNode;
		copyNode->next = nextCopyNode;

		// ���½ڵ�
		currNode = nextNode;
		

	}
	// �˳�֮������������ڵ�
	currNode->next = NULL;

	return copyNodeHead;


}

