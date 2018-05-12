#pragma once


/* ��ת���� */

#include "ListNode.h"

/* ˼·������������ָ���סhead��ǰ���ͺ�����Ȼ��head��nextָ��ָ������ǰ��������head����Ϊ���ĺ��� */

ListNode* reverseList(ListNode* head) {
	if (!head || !head->next) return head;

	ListNode *pre = nullptr;
	ListNode *succ = head->next;

	while (head) {
		head->next = pre;
		pre = head;
		head = succ;
		if(head)
			succ = head->next;
	}

	return pre;
}
