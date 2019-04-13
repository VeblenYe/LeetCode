
#include "LeetCode.h"

ListNode *merge(ListNode *l, ListNode *r) {
	auto dummyHead = new ListNode(0);
	auto cur = dummyHead;
	while (l && r) {
		if (l->val <= r->val) {
			cur->next = l;
			cur = cur->next;
			l = l->next;
		}
		else {
			cur->next = r;
			cur = cur->next;
			r = r->next;
		}
	}
	if (l)
		cur->next = l;
	else if (r)
		cur->next = r;
	return dummyHead->next;
}
ListNode *mergeSort(ListNode *head) {
	if (head->next == nullptr)
		return head;

	auto p = head;
	auto q = head;
	ListNode * pre = nullptr;
	while (q && q->next) {
		pre = p;
		p = p->next;
		q = q->next->next;
	}
	pre->next = nullptr;
	auto l = mergeSort(head);
	auto r = mergeSort(p);
	return merge(l, r);
}

ListNode *sortList(ListNode *head) {
	return head == nullptr ? nullptr : mergeSort(head);
}
