

/* 二叉树的最大深度 */

/* 当遇到树问题时，请先思考一下两个问题：

你能确定一些参数，从该节点自身解决出发寻找答案吗？
你可以使用这些参数和节点本身的值来决定什么应该是传递给它子节点的参数吗？
如果答案都是肯定的，那么请尝试使用 “自顶向下” 的递归来解决此问题。

或者你可以这样思考：对于树中的任意一个节点，如果你知道它子节点的答案，你能计算出该节点的答案吗？
如果答案是肯定的，那么 “自底向上” 的递归可能是一个不错的解决方法。*/

#include "BinaryTree.h"

#include <algorithm>

using std::max;

/* 自底向上 */

int maxDepth(TreeNode *root) {
	if (!root) return 0;

	int l = maxDepth(root->left);
	int r = maxDepth(root->right);

	return max(l, r) + 1;
}

/* 自顶向下 */

int answer = 0;
int maxDepth(TreeNode *root, int depth) {
	if (!root) return 0;
	
	if (!root->left && !root->right)
		answer = max(answer, depth);

	maxDepth(root->left, depth + 1);
	maxDepth(root->right, depth + 1);
}
