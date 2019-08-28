

#include "LeetCode.h"


// ˼·��ʹ��˫ָ�룬��ָ��ָ�������е�ǰ���ظ���Ԫ�أ���ָ�븺�����������ظ�Ԫ��
// �������ӿ���ָ�벢����


ListNode *deleteDuplicates(ListNode *head) {
	if (!head || !head->next)
		return head;

	auto dummy = new ListNode(0);
	dummy->next = head;
	auto pre = dummy; // ��ָ��
	while (pre->next) {
		auto cur = pre->next;	// ��ָ��
		while (cur->next && cur->val == cur->next->val) {	// ���������ظ�Ԫ�أ���ɾ��
			auto tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		if (cur != pre->next) {	// ���curȷʵ�����ظ�Ԫ�أ���cur�����һ���ظ�Ԫ�أ�������ָ���̲�ɾ��cur
			pre->next = cur->next;
			delete cur;
		}
		else
			pre = pre->next;	// cur�����ظ�Ԫ�أ��ƶ���ָ��
	}
	return dummy->next;
}
