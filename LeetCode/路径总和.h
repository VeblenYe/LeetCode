#pragma once


/* ·���ܺ� */

#include "BinaryTree.h"

/* �Զ����£������ĺ�ӦΪ�ܺͼ�ȥ������ֵ�Ĳ���ϵݹ飬֪��Ҷ�ڵ�ļ�ֵ�Ͳ�ֵ���ʱ��������true */

bool hasPathSum(TreeNode *root, int sum) {
	if (!root) return false;

	if (root->val == sum && !root->left && !root->right)	// �ݹ��
		return true;

	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
