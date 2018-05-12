#pragma once


/* 合并两个有序链表 */

#include "ListNode.h"

/* 思路：递归 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode *head = nullptr;

	if (l1 && l2) {
		if (l1->val <= l2->val) {
			head = l1;
			head->next = mergeTwoLists(l1->next, l2);
		}
		else {
			head = l2;
			head->next = mergeTwoLists(l1, l2->next);
		}
	}
	if (!l1)
		head = l2;
	if (!l2)
		head = l1;

	return head;
}
