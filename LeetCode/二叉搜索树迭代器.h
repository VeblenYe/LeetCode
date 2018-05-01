#pragma once


/* 二叉搜索树迭代器 */

#include "BinarySearchTree.h"

#include <vector>
#include <stack>


using std::vector;
using std::stack;

/* 思路一，中序遍历，存入vector */

class BSTIterator1 {
public:
	BSTIterator1(TreeNode *root) : cur(0) {
		stack<TreeNode *> s;
		while (root || !s.empty()) {
			if (root) {
				s.push(root);
				root = root->left;
			}
			else {
				root = s.top();
				s.pop();
				ivec.push_back(root->val);
				root = root->right;
			}
		}
	}

	bool hasNext() {
		return cur < ivec.size();
	}

	int next() {
		return ivec[cur++];
	}
private:
	vector<int> ivec;
	int cur;
};

/* 思路二，用栈 */

class BSTIterator2 {
public:
	BSTIterator2(TreeNode *root) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}

	bool hasNext() {
		return !s.empty();
	}

	int next() {
		auto x = s.top();
		s.pop();
		auto res = x->val;
		while (x->right) {
			x = x->right;
			while (x) {
				s.push(x);
				x = x->left;
			}
		}
		return res;
	}
private:
	stack<TreeNode *> s;
};
