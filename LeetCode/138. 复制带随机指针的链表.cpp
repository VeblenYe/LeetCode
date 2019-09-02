
#include "LeetCode.h"


// ˼·�����ȸ���ÿһ���ڵ㣬��������Դ�ڵ�֮��Ȼ���ٸ������ָ��ָ��Ľڵ㣬��������������


RandomListNode *copyRandomList(RandomListNode *head) {
	if (!head)
		return nullptr;

	RandomListNode *cur = head;
	RandomListNode *clone;

	while (cur) {
		// ���ƽڵ㲢������Դ�ڵ�֮��
		clone = new RandomListNode(cur->label);
		clone->next = cur->next;
		cur->next = clone;
		cur = clone->next;
	}

	cur = head;
	while (cur && cur->next) {
		// �������ָ��
		if (cur->random)
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}

	cur = head;
	clone = cur->next;
	while (cur) {
		// ������������
		auto tmp = cur->next;
		cur->next = tmp->next;
		if (tmp->next)
			tmp->next = tmp->next->next;
		cur = cur->next;
	}

	return clone;
}
