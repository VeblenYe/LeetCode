

#include "LeetCode.h"
#include "BinarySearchTree.h"


// 第一种思路，根据数组转换二叉树，搜索链表中点，递归构建

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



// 第二种思路，根据中序遍历，递归创建


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

	auto left = convertListToBST(head, l, mid - 1);	// 将左侧链表转换

	auto node = new TreeNode(head->val);	// 当前节点连接左子树
	node->left = left;

	head = head->next;	// 转换当前节点的右侧链表，并连接
	node->right = convertListToBST(head, mid + 1, r);
	return node;
}

TreeNode *sortedListToBST1(ListNode *head) {

	if (!head)
		return nullptr;

	auto size = countSize(head);

	return convertListToBST(head, 0, size - 1);
}
