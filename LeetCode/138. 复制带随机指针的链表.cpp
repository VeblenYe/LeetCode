
#include "LeetCode.h"


// 思路：首先复制每一个节点，并连接在源节点之后，然后再复制随机指针指向的节点，最后分离两个链表


RandomListNode *copyRandomList(RandomListNode *head) {
	if (!head)
		return nullptr;

	RandomListNode *cur = head;
	RandomListNode *clone;

	while (cur) {
		// 复制节点并连接在源节点之后
		clone = new RandomListNode(cur->label);
		clone->next = cur->next;
		cur->next = clone;
		cur = clone->next;
	}

	cur = head;
	while (cur && cur->next) {
		// 复制随机指针
		if (cur->random)
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}

	cur = head;
	clone = cur->next;
	while (cur) {
		// 分离两个链表
		auto tmp = cur->next;
		cur->next = tmp->next;
		if (tmp->next)
			tmp->next = tmp->next->next;
		cur = cur->next;
	}

	return clone;
}
