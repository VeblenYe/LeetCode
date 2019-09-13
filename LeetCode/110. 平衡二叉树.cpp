
/* 平衡二叉树 */

#include "BinarySearchTree.h"
#include "LeetCode.h"

/* 思路，求出当前节点的左右子树深度，如果相差大于一，则返回false，否则继续判断
左右子树是否各自为平衡二叉树 */
// 优化，自底向上，每个节点只遍历一次

bool aux(TreeNode *root, int &depth) {
	if (!root) {
		depth = 0;
		return true;
	}

	int left, right;
	if (aux(root->left, left) && aux(root->right, right)) {
		if (abs(left - right) <= 1) {
			depth = 1 + max(left, right);
			return true;
		}
	}

	return false;
}

bool isBalanced(TreeNode *root) {
	if (!root) return true;
	int depth = 0;
	return aux(root, depth);
}
