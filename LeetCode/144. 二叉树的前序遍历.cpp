

#include "BinaryTree.h"


#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::reverse;

/* 前序遍历 */

/* 递归版 */

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


/* 迭代版一 */

vector<int> preorderTraversal2(TreeNode *root) {
	if (!root) return {};
	stack<TreeNode *> s;		// 利用栈实现
	vector<int> ivec;
	s.push(root);
	while (!s.empty()) {
		auto x = s.top();
		ivec.push_back(x->val);	// 先访问根节点
		s.pop();
		if (x->right) s.push(x->right);	// 将右节点推入栈中
		if (x->left) s.push(x->left);	// 将左节点推入栈中
	}
	return ivec;
}

/* 迭代版二 */

void visitAlongLeftBranch(TreeNode *root, vector<int> &ivec, stack<TreeNode *> &s) {	// 传入必须是引用
	auto x = root;
	while (x) {
		ivec.push_back(x->val);
		s.push(x->right);		// 其实这里不用判断也行，因为如果是NULL，则不会做任何操作
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
