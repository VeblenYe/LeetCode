

#include "LeetCode.h"


ListNode *reverseBetween(ListNode *head, int m, int n) {
	auto dummy = new ListNode(0);
	dummy->next = head;
	auto pre = dummy;
	for (int i = 0; i < m - 1; ++i)
		pre = pre->next;
	auto curr = pre->next;
	for (int i = m; i < n; ++i) {
		auto tmp = curr->next;
		curr->next = tmp->next;
		tmp->next = pre->next;
		pre->next = tmp;
	}
	return dummy->next;
}
