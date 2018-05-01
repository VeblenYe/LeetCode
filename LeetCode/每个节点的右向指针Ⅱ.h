#pragma once


/* 每个节点的右向指针Ⅱ，没有假设 */

#include "BinaryTree.h"
#include <queue>

using std::queue;

/* 思路一，还是可以用层次遍历 */
void connect(TreeNode *root) {
	if (!root) return;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		for (int n = q.size(); n > 0; n--) {
			auto x = q.front();
			q.pop();
			if (n != 1)
				x->next = q.front();
			else
				x->next = nullptr;
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
		}
	}
}
