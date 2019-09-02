

#include "BinarySearchTree.h"


void flatten(TreeNode *root) {
	while (root) {
		if (root->left) {
			// 如果有左子树，则找左子树的最右节点
			auto most_right = root->left;
			while (most_right->right)
				most_right = most_right->right;
			// 将根节点右孩子移到最右节点右孩子处
			most_right->right = root->right;
			// 移动整个左子树到根节点右孩子
			root->right = root->left;
			// 将左子树置空
			root->left = nullptr;
		}
		// 移动到右节点继续展开
		root = root->right;
	}

}
