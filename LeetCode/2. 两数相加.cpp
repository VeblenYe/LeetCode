
#include "ListNode.h"


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	auto head = new ListNode(0);
	auto cur = head;
	size_t carry = 0;
	while (l1 || l2 || carry) {
		if (l1) {
			carry += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			carry += l2->val;
			l2 = l2->next;
		}
		cur->next = new ListNode(carry % 10);
		cur = cur->next;
		carry /= 10;
	}
	return head->next;
}
