

/* 回文链表 */

#include "ListNode.h"
#include "反转链表.h"


// 取链表中点，反转后半部分，判断是否与前半部分相等

bool isPalindrome(ListNode* head) {
	if (!head || !head->next)
		return true;

	auto slow = head;
	auto fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast) {
		slow->next = reverseList(slow->next);
		slow = slow->next;
	}
	else
		slow = reverseList(slow);

	while (slow) {
		if (head->val != slow->val)
			return false;
		head = head->next;
		slow = slow->next;
	}

	return true;
}

