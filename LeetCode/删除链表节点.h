#pragma once


/* ɾ������ڵ� */

#include "ListNode.h"

/* ˼·������node��node->next��ֵ��Ȼ��ɾ��node->next */

void deleteNode(ListNode *node) {
	if (!node || !node->next) return;
	node->val = node->next->val;
	node->next = node->next->next;
}
