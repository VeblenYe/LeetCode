
/* 路径总和 */

#include "BinaryTree.h"

/* 自顶而下，子树的和应为总和减去根结点键值的差，不断递归，知道叶节点的键值和差值相等时，即返回true */

bool hasPathSum(TreeNode *root, int sum) {
	if (!root) return false;

	if (root->val == sum && !root->left && !root->right)	// 递归基
		return true;

	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
