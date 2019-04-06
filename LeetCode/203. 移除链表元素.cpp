
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


/* ˼·����ס��ǰ�ڵ��ǰ���ͺ�̾����ײ����ˣ�ע�����ɾ��ͷ�ڵ����� */
ListNode* removeElements(ListNode* head, int val) {
	auto prev = head;
	auto cur = head;
	auto next = cur;
	while (cur != nullptr) {
		next = cur->next;
		if (cur->val == val) {
			delete cur;
			if (cur == head) {
				head = next;
				prev = head;
			}
			else
				prev->next = next;
		}
		else
			prev = cur;
		cur = next;
	}
}
