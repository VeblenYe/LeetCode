#pragma once


/* 环形链表 */


#include "ListNode.h"

// 快慢指针法，若链表中有环，则快指针会追上慢指针

bool hasCycle(ListNode *head) {
	if (!head || !head->next)
		return false;

	auto slow = head;
	auto fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}

	return false;
}

