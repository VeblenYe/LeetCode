#pragma once


/* ��������������������� */


#include "BinarySearchTree.h"

/* ˼·�Ͷ�������࣬����������һЩ���������������� */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || root == p || root == q)
		return root;

	if ((p->val <= root->val) && (root->val < q->val) ||
		(root->val < p->val) && (q->val <= root->val))
		return root;

	if (p->val <= root->val) return lowestCommonAncestor(root->left, p, q);
	else return lowestCommonAncestor(root->right, p, q);
}
