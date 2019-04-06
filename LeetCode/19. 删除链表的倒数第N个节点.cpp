
/* 删除链表的倒数第N个节点 */

#include "ListNode.h"

/* 思路，快慢指针 */

ListNode* removeNthFromEnd(ListNode *head, int n) {
	auto slow = head;
	auto fast = head;

	while (n--)
		fast = fast->next;

	if (fast) {		// 如果fast超出链表，则删除头节点
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		return head;
	}
	else
		return head->next;
}
