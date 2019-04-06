
/* 平衡二叉树 */

#include "BinarySearchTree.h"
#include <algorithm>

using std::max;
using std::abs;

/* 思路，求出当前节点的左右子树深度，如果相差大于一，则返回false，否则继续判断
左右子树是否各自为平衡二叉树 */

int height(TreeNode *root) {
	if (!root) return 0;

	auto l = height(root->left);
	auto r = height(root->right);

	return max(l, r) + 1;
}

bool isBalanced(TreeNode *root) {
	if (!root) return true;

	if (abs(height(root->left) - height(root->right)) <= 1
		&& isBalanced(root->left) && isBalanced(root->right))
		return true;
	return false;
}
