

#include "BinarySearchTree.h"

#include "LeetCode.h"

/* ��֤���������� */

/*  �ڵ��������ֻ����С�ڵ�ǰ�ڵ������
	�ڵ��������ֻ�������ڵ�ǰ�ڵ������
	�������������������������Ҳ�Ƕ����������� */

/* ˼·һ������������� */

bool isValidBST(TreeNode *root) {

	if (!root) return true;

	stack<TreeNode *> s;
	
	TreeNode *pre = nullptr;
	while (root || !s.empty()) {
		if (root) {
			s.push(root);
			root = root->left;
		}
		else {
			root = s.top();
			s.pop();
			if (pre && (root->val <= pre->val))
				return false;
			pre = root;
			root = root->right;
		}
	}

	return true;
}
