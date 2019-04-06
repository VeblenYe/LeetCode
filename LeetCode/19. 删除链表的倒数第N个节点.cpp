
/* ɾ������ĵ�����N���ڵ� */

#include "ListNode.h"

/* ˼·������ָ�� */

ListNode* removeNthFromEnd(ListNode *head, int n) {
	auto slow = head;
	auto fast = head;

	while (n--)
		fast = fast->next;

	if (fast) {		// ���fast����������ɾ��ͷ�ڵ�
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
