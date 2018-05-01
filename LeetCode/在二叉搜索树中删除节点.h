#pragma once


/* 在二叉搜索树中删除节点 */


#include "BinarySearchTree.h"


TreeNode *deleteNode(TreeNode *root, int key) {

	if (!root) return nullptr;

	if (root->val == key) {		// 如果当前节点即为要删除节点
		if (root->left) {		// 有左子树，则查找左子树中最大元素，并交换位置，再递归在左子树中删除节点
			auto next = root->left;
			while (next->right)
				next = next->right;

			next->val ^= root->val;		// 不需要临时变量的swap，知道就行，并不值得推荐
			root->val ^= next->val;
			next->val ^= root->val;

			root->left = deleteNode(root->left, key);
		}
		else if (root->right) {	// 如果没有左子树，但有右子树，则查找右子树中最小元素，并交换位置，再递归在右子树中删除节点
			auto next = root->right;
			while (next->left)
				next = next->left;

			next->val ^= root->val;		// 不需要临时变量的swap
			root->val ^= next->val;
			next->val ^= root->val;

			root->right = deleteNode(root->right, key);
		}
		else {					// 没有任何子树，直接删除并返回nullptr，递归基
			delete root;
			return nullptr;
		}
	}
	else if (key < root->val && root->left)	// 查找节点在左子树中
		root->left = deleteNode(root->left, key);
	else if (root->val < key && root->right)	// 查找节点在右子树中
		root->right = deleteNode(root->right, key);

	return root;	// 没有找到节点
}

