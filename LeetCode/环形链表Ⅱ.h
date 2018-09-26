#pragma once


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


/* 判断链表是否有环，若有，则返回环开始的第一个节点 */
/* 思路，用双指针判断是否有环，然后记录相交节点，再从头与相交节点一起前进，相遇节点即为环开始节点 */
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
