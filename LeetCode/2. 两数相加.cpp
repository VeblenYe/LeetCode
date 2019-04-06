
#include "ListNode.h"


/* 两个思路一样，但是自己实现的又臭又长。。 */
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;

	int carry = 0;
	int cur;
	ListNode *head = nullptr;
	ListNode *cur_node = nullptr;
	while (l1 && l2) {
		int sum = l1->val + l2->val + carry;
		cur = sum % 10;
		if (head == nullptr) {
			head = new ListNode(cur);
			cur_node = head;
		}
		else {
			cur_node->next = new ListNode(cur);
			cur_node = cur_node->next;
		}
		carry = sum / 10;
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1) {
		if ((l1->val + carry) == 10) {
			carry = 1;
			cur_node->next = new ListNode(0);
			cur_node = cur_node->next;
		}
		else {
			cur_node->next = new ListNode(l1->val);
			cur_node = cur_node->next;
			carry = 0;
		}
		l1 = l1->next;
	}

	while (l2) {
		if ((l2->val + carry) == 10) {
			carry = 1;
			cur_node->next = new ListNode(0);
			cur_node = cur_node->next;
		}
		else {
			cur_node->next = new ListNode(l2->val);
			cur_node = cur_node->next;
			carry = 0;
		}
		l2 = l2->next;
	}

	if (carry == 1)
		cur_node->next = new ListNode(1);

	return head;
}


ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
	auto head = new ListNode(0);
	auto cur = head;
	int carry = 0;
	while (l1 || l2) {
		int x = (l1 == nullptr) ? 0 : l1->val;
		int y = (l2 == nullptr) ? 0 : l2->val;
		int sum = x + y + carry;
		carry = sum / 10;
		cur->next = new ListNode(carry % 10);
		cur = cur->next;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}

	if (carry > 0)
		cur->next = new ListNode(carry);

	return head->next;
}
