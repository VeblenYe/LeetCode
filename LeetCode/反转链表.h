#pragma once


/* 反转链表 */

#include "ListNode.h"

/* 思路：用两个额外指针记住head的前驱和后驱，然后将head的next指针指向它的前驱，并将head更新为它的后驱 */

ListNode* reverseList(ListNode* head) {
	if (!head || !head->next) return head;

	ListNode *pre = nullptr;
	ListNode *succ = head->next;

	while (head) {
		head->next = pre;
		pre = head;
		head = succ;
		if(head)
			succ = head->next;
	}

	return pre;
}
