#pragma once


/* 二叉树的最深公共祖先 */


#include "BinaryTree.h"
#include <vector>

/* 思路，如果根节点root是q或者p，则root是其最深公共祖先，如果不是，则递归遍历左右子树，
只有当在左右子树都分别找到p和q时，这是的root就是最深公共祖先，如果左右子树中只有一个树
找到了p和q，则该子树的根节点为最深公共祖先 */

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (!root || root == p || root == q)
		return root;
	auto left = lowestCommonAncestor(root->left, p, q);
	auto right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	return left ? left : right;
}
