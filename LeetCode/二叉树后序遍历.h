#pragma once


#include "BinaryTree.h"

#include <vector>
#include <stack>

using std::vector;
using std::stack;

/* ������� */

/* �ݹ�� */

vector<int> postorderTraversal1(TreeNode* root) {
	vector<int> result;
	dfs(root, result);
	return result;
}

void dfs(TreeNode *root, vector<int> &ivec) {
	if (!root) return;
	dfs(root->left, ivec);
	dfs(root->right, ivec);
	ivec.push_back(root->val);
}

/* ������ */

vector<int> postorderTraversal2(TreeNode* root) {
	if (!root) return {};
	stack<TreeNode *> s;		// ����ջʵ��
	vector<int> ivec;
	s.push(root);
	while (!s.empty()) {
		auto x = s.top();
		ivec.push_back(x->val);	// �ȷ��ʸ��ڵ�
		s.pop();
		if (x->left) s.push(x->left);	// ����ڵ�����ջ��
		if (x->right) s.push(x->right);	// ���ҽڵ�����ջ��
	}
	reverse(ivec.begin(), ivec.end());	// �����󣬷�ת
	return ivec;
}

//����һ����ǰ�ڵ㱻��ȡ������Ϊ�������Һ��ӣ�������һ�ζ�ȡ��Ϊ�����Һ��ӡ�
//���������Һ���ķ�ʽ���ӽڵ�ѹջ��

vector<int> postorderTraversal3(TreeNode *root) {
	vector<int> res;
	if (!root)
		return res;
	stack<TreeNode *> st;
	TreeNode * pre = nullptr;
	st.push(root);
	while (!st.empty()) {
		TreeNode * p = st.top();
		if ((!p->left && !p->right) ||
			(pre && (pre == p->left || pre == p->right))) {
			res.push_back(p->val);
			st.pop();
			pre = p;
		}
		else {
			if (p->right) st.push(p->right);
			if (p->left) st.push(p->left);
		}
	}
	return res;
}
