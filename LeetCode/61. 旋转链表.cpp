
#include "ListNode.h"
 


/* ����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ��� */
/* ˼·�����������ȫ������ͨ��ȡ��ȷ���ƶ��Ľڵ� */
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
