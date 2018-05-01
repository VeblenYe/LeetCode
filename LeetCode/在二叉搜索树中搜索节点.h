#pragma once


/* ÔÚ¶þ²æËÑË÷Ê÷ÖÐËÑË÷ */

#include "BinarySearchTree.h"

/* µÝ¹é°æ */

TreeNode *searchBST1(TreeNode *root, int val) {
	
	if (!root || root->val == val) return root;

	if (val < root->val)
		return searchBST1(root->left, val);

	return searchBST1(root->right, val);

}

/* µü´ú°æ */

TreeNode *searchBST2(TreeNode *root, int val) {
	while (root && root->val != val) {
		if (root->val < val)
			root = root->right;
		else
			root = root->left;
	}
	return root;
}
