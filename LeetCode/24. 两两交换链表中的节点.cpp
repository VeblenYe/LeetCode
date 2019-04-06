
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


/* �ݹ�ⷨ */
ListNode *swapPairs1(ListNode *head) {
	if (!head || !head->next)
		return head;
	auto next = head->next;
	head->next = swapPairs1(next->next);
	next->next = head;
	return next;
}


/* �����ⷨ */
ListNode *swapPairs2(ListNode *head) {
	if (!head || !head->next)
		return head;
	ListNode res(-1);
	res.next = head;
	ListNode * last = &res;
	ListNode * cur = head;
	while (cur && cur->next) {
		ListNode *tmp = cur->next->next;
		last->next = cur->next;
		last = cur;
		cur->next->next = cur;
		cur->next = tmp;
		cur = tmp;
	}
	return res.next;
}
