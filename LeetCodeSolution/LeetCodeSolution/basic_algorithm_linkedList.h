#ifndef basic_algorithm_linkedList_
#define basic_algorithm_linkedList_


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class CLinkedList
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n);
	ListNode* reverseList(ListNode* head);
};



#endif // !basic_algorithm_linkedList_




#pragma once
