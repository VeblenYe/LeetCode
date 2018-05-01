#pragma once


#include "BinaryTree.h"

#include <vector>
#include <stack>

using std::vector;
using std::stack;

/* 中序遍历 */

/* 递归版 */

void inDfs(TreeNode *root, vector<int> &ivec) {
	if (!root) return;
	inDfs(root->left, ivec);
	ivec.push_back(root->val);
	inDfs(root->right, ivec);
}

vector<int> inorderTraversal1(TreeNode* root) {
	vector<int> ivec;
	inDfs(root, ivec);
	return ivec;
}



/* 迭代版一，中序遍历的顺序为：左，中，右。
其经典思路为：当前节点有左子节点时，将当前节点压栈，并将左子节点作为当前处理；
当前节点无左子节点时，表示左子树都已遍历完成，此时访问当前节点，并将右子节点设为当前节点。*/

vector<int> inorderTraversal2(TreeNode* root) {
	if (!root) return {};
	stack<TreeNode *> s;
	vector<int> ivec;
	auto p = root;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			ivec.push_back(p->val);
			s.pop();
			p = p->right;
		}
	}
	return ivec;
}

/* 迭代版二 */

void goAlongLeftBranch(TreeNode *root, vector<int> &ivec, stack<TreeNode *> &s) {
	while (root) {
		s.push(root);
		root = root->left;
	}
}

vector<int> inorderTraversal3(TreeNode *root) {
	if (!root) return {};
	vector<int> ivec;
	stack<TreeNode *> s;
	auto x = root;

	while (true) {
		goAlongLeftBranch(x, ivec, s);
		if (s.empty()) break;
		x = s.top();
		ivec.push_back(x->val);
		s.pop();
		x = x->right;
	}

	return ivec;
}
