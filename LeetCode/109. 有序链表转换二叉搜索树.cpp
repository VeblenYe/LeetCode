

#include "LeetCode.h"
#include "BinarySearchTree.h"


// ��һ��˼·����������ת�������������������е㣬�ݹ鹹��

ListNode *findMiddleElement(ListNode *head) {
	if (!head)
		return nullptr;

	auto prev = (ListNode *)nullptr;
	auto slow = head;
	auto fast = head;
	while (fast && fast->next) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (prev)
		prev->next = nullptr;

	return slow;
}


TreeNode *sortedListToBST(ListNode *head) {

	if (!head)
		return nullptr;

	auto mid = findMiddleElement(head);

	auto node = new TreeNode(mid->val);

	if (mid == head)
		return node;

	node->left = sortedListToBST(head);
	node->right = sortedListToBST(mid->next);

	return node;
}



// �ڶ���˼·����������������ݹ鴴��


int countSize(ListNode *head) {
	int i = 0;
	while (head) {
		++i;
		head = head->next;
	}
	return i;
}


TreeNode *convertListToBST(ListNode *head, int l, int r) {
	if (r < l)
		return nullptr;

	auto mid = (l + r) >> 1;

	auto left = convertListToBST(head, l, mid - 1);	// ���������ת��

	auto node = new TreeNode(head->val);	// ��ǰ�ڵ�����������
	node->left = left;

	head = head->next;	// ת����ǰ�ڵ���Ҳ�����������
	node->right = convertListToBST(head, mid + 1, r);
	return node;
}

TreeNode *sortedListToBST1(ListNode *head) {

	if (!head)
		return nullptr;

	auto size = countSize(head);

	return convertListToBST(head, 0, size - 1);
}
