

#include "BinarySearchTree.h"

#include "LeetCode.h"

/* 验证二叉搜索树 */

/*  节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。 */

/* 思路一，利用中序遍历 */

bool isValidBST(TreeNode *root) {

	if (!root) return true;

	stack<TreeNode *> s;
	
	TreeNode *pre = nullptr;
	while (root || !s.empty()) {
		if (root) {
			s.push(root);
			root = root->left;
		}
		else {
			root = s.top();
			s.pop();
			if (pre && (root->val <= pre->val))
				return false;
			pre = root;
			root = root->right;
		}
	}

	return true;
}
