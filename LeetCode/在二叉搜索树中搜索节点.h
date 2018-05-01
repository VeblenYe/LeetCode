#pragma once


/* �ڶ��������������� */

#include "BinarySearchTree.h"

/* �ݹ�� */

TreeNode *searchBST1(TreeNode *root, int val) {
	
	if (!root || root->val == val) return root;

	if (val < root->val)
		return searchBST1(root->left, val);

	return searchBST1(root->right, val);

}

/* ������ */

TreeNode *searchBST2(TreeNode *root, int val) {
	while (root && root->val != val) {
		if (root->val < val)
			root = root->right;
		else
			root = root->left;
	}
	return root;
}
