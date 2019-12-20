#ifndef basic_algorithm_linkedList_
#define basic_algorithm_linkedList_


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};

class NodeWithRandom {
public:
	int val;
	NodeWithRandom* next;
	NodeWithRandom* random;

	NodeWithRandom(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
class MyLinkedList {
public:
	int val;
	MyLinkedList* next;
	/** Initialize your data structure here. */
	MyLinkedList() {
		
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		MyLinkedList* currNode = this;
		while (index)
		{
			currNode = currNode->next;
		}
		return currNode->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		MyLinkedList* insertNode, *nextNode;
		insertNode->val = this->val;
		if (this != NULL)
			nextNode = this->next;  // Î´Íê£¬´ýÐø
		this->val = val;

	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		MyLinkedList* insertNode, *currNode = this, *preNode = this;
		insertNode->val = val;
		while (currNode != NULL)
		{
			preNode = currNode;
			currNode = currNode->next;
		}
		if (preNode == NULL)
			this->val = val;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {

	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {

	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2);
};



#endif // !basic_algorithm_linkedList_




#pragma once
