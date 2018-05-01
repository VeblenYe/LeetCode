#pragma once


/* 删除链表节点 */

#include "ListNode.h"

/* 思路，交换node和node->next的值，然后删除node->next */

void deleteNode(ListNode *node) {
	if (!node || !node->next) return;
	node->val = node->next->val;
	node->next = node->next->next;
}
