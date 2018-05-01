#pragma once

#include "BinaryTree.h"


#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::reverse;

/* ǰ����� */

/* �ݹ�� */

void preDfs(TreeNode *root, vector<int> &ivec) {
	if (!root) return;
	ivec.push_back(root->val);
	preDfs(root->left, ivec);
	preDfs(root->right, ivec);
}

vector<int> preorderTraversal1(TreeNode *root) {
	vector<int> result;
	preDfs(root, result);
	return result;
}


/* ������һ */

vector<int> preorderTraversal2(TreeNode *root) {
	if (!root) return {};
	stack<TreeNode *> s;		// ����ջʵ��
	vector<int> ivec;
	s.push(root);
	while (!s.empty()) {
		auto x = s.top();
		ivec.push_back(x->val);	// �ȷ��ʸ��ڵ�
		s.pop();
		if (x->right) s.push(x->right);	// ���ҽڵ�����ջ��
		if (x->left) s.push(x->left);	// ����ڵ�����ջ��
	}
	return ivec;
}

/* ������� */

void visitAlongLeftBranch(TreeNode *root, vector<int> &ivec, stack<TreeNode *> &s) {	// �������������
	auto x = root;
	while (x) {
		ivec.push_back(x->val);
		s.push(x->right);		// ��ʵ���ﲻ���ж�Ҳ�У���Ϊ�����NULL���򲻻����κβ���
		x = x->left;
	}
}

vector<int> preorderTraversal3(TreeNode *root) {
	if (!root) return {};
	vector<int> ivec;
	stack<TreeNode *> s;
	auto x = root;

	while (true) {
		visitAlongLeftBranch(x, ivec, s);
		if (s.empty()) break;
		x = s.top();
		s.pop();
	}

	return ivec;
}
