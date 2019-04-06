

/* �������� */

#include "ListNode.h"
#include "��ת����.h"


// ȡ�����е㣬��ת��벿�֣��ж��Ƿ���ǰ�벿�����

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

