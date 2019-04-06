
#include "ListNode.h"

/* 思路，记住当前节点的前驱和后继就容易操作了，注意的是删除头节点的情况 */
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
