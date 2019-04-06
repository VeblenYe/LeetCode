
/* ÿ���ڵ������ָ��񣺼����������������� */

#include "BinaryTree.h"
#include <queue>

using std::queue;

/* ˼·һ���Զ����£���α��� */

void connect1(TreeNode *root) {
	if (!root) return;
	root->next = NULL;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		auto x = q.front();
		if (!x->left || !x->right) return;
		x->left->next = x->right;
		if (x->next)
			x->right->next = x->next->left;
		else
			x->right->next = NULL;
		q.pop();
		q.push(x->left);
		q.push(x->right);
	}
}

/* ��������˼·��࣬�����õݹ� */

void connectHelper(TreeNode *root) {
	if (!root->left && !root->right)
		return;
	if (root->left) {
		root->left->next = root->right;
		connectHelper(root->left);
	}
	if (root->right) {
		if (root->next)
			root->right->next = root->next->left;
		else
			root->right->next = nullptr;
		connectHelper(root->right);
	}
}

void connect2(TreeNode *root) {
	if (!root) return;
	root->next = nullptr;
	connectHelper(root);
}
