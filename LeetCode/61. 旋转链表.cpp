
#include "ListNode.h"
 


/* 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数 */
/* 思路，先求出链表全长，再通过取余确定移动的节点 */
ListNode* rotateRight(ListNode* head, int k) {
	if (!head || !head->next)
		return head;

	ListNode *cur = head;
	ListNode *last;
	int len = 0;
	while (cur) {
		last = cur;
		cur = cur->next;
		++len;
	}

	int i = k % len;
	if (i == 0)
		return head;
	else {
		last->next = head;
		int j = len - i;
		while (--j)
			head = head->next;
		ListNode *result = head->next;
		head->next = nullptr;
		return result;
	}
}
