#pragma once


/* �ڶ����������в��� */

#include "BinarySearchTree.h"


TreeNode *insertIntoBST(TreeNode *root, int val) {
	
	if (!root) 
		return new TreeNode(val);

	if (root->val <= val)
		root->right = insertIntoBST(root->right, val);
	else if (val < root->val)
		root->left = insertIntoBST(root->left, val);
		
	return root;
}
