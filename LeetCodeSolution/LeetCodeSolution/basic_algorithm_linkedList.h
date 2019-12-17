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
	ListNode* reverseList2(ListNode* head);
	ListNode* reverseList3(ListNode* head);
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
	ListNode* removeElements(ListNode* head, int val);
	ListNode* removeElements2(ListNode* head, int val);
	bool isPalindrome(ListNode* head);
};



#endif // !basic_algorithm_linkedList_




#pragma once
