#pragma once


#include "BinaryTree.h"

#include <vector>
#include <stack>

using std::vector;
using std::stack;

/* 后序遍历 */

/* 递归版 */

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

/* 迭代版 */

vector<int> postorderTraversal2(TreeNode* root) {
	if (!root) return {};
	stack<TreeNode *> s;		// 利用栈实现
	vector<int> ivec;
	s.push(root);
	while (!s.empty()) {
		auto x = s.top();
		ivec.push_back(x->val);	// 先访问根节点
		s.pop();
		if (x->left) s.push(x->left);	// 将左节点推入栈中
		if (x->right) s.push(x->right);	// 将右节点推入栈中
	}
	reverse(ivec.begin(), ivec.end());	// 中右左，翻转
	return ivec;
}

//方案一：当前节点被读取的条件为：无左右孩子，或者上一次读取的为其左右孩子。
//否则按照先右后左的方式对子节点压栈。

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
