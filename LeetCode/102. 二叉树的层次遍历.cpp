
/* 二叉树的层次遍历 */

#include "BinaryTree.h"

#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pow;

/* 利用队列先进先出实现 */

vector<vector<int>> levelOrder(TreeNode *root) {
	vector<vector<int>> result;
	if (!root) return result;
	queue<TreeNode *> qt;
	auto x = root;
	qt.push(x);
	for (int level = 0; !qt.empty(); level++) {
		result.push_back({});
		for (int n = qt.size(); n > 0; n--) {	// 第一次计数即为该层所拥有的元素个数
			x = qt.front();
			result[level].push_back(x->val);
			qt.pop();
			if (x->left) qt.push(x->left);
			if (x->right) qt.push(x->right);
		}
	}
	return result;
}
