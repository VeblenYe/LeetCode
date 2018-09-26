#pragma once


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


/* �ж������Ƿ��л������У��򷵻ػ���ʼ�ĵ�һ���ڵ� */
/* ˼·����˫ָ���ж��Ƿ��л���Ȼ���¼�ཻ�ڵ㣬�ٴ�ͷ���ཻ�ڵ�һ��ǰ���������ڵ㼴Ϊ����ʼ�ڵ� */
ListNode *detectCycle(ListNode *head) {
	if (!head || !head->next)
		return nullptr;

	ListNode *slow = head;
	ListNode *fast = head;

	while (fast&&fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	if (fast == nullptr)
		return nullptr;

	while (head&&slow) {
		if (head == slow)
			return head;
		head = head->next;
		slow = slow->next;
	}

	return nullptr;
}
