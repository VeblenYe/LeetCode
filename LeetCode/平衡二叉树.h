#pragma once


/* ƽ������� */

#include "BinarySearchTree.h"
#include <algorithm>

using std::max;
using std::abs;

/* ˼·�������ǰ�ڵ������������ȣ����������һ���򷵻�false����������ж�
���������Ƿ����Ϊƽ������� */

int height(TreeNode *root) {
	if (!root) return 0;

	auto l = height(root->left);
	auto r = height(root->right);

	return max(l, r) + 1;
}

bool isBalanced(TreeNode *root) {
	if (!root) return true;

	if (abs(height(root->left) - height(root->right)) <= 1
		&& isBalanced(root->left) && isBalanced(root->right))
		return true;
	return false;
}
