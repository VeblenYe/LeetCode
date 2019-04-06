
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


/* 记住奇数、偶数的起始节点，再逐步记录要交换的节点，进行交换即可 */
ListNode* oddEvenList(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return head;

	auto odd = head;
	auto even = head->next;

	auto odd_cur = odd->next->next;
	auto even_cur = even;
	while (odd_cur) {
		odd->next = odd_cur;
		even_cur->next = odd_cur->next;
		odd_cur->next = even;
		odd = odd_cur;
		even_cur = even_cur->next;
		if (even_cur)
			odd_cur = even_cur->next;
		else
			break;
	}

	return head;
}
