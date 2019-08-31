

#include "BinarySearchTree.h"


// 思路：递归翻转子树


TreeNode *invertTree(TreeNode *root) {
	if (!root)
		return root;

	auto tmp = root->left;	// 记录原左子树
	root->left = invertTree(root->right);	// 将左子树翻转为右子树
	root->right = invertTree(tmp);	// 将右子树翻转为原左子树                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

	return root;
}
