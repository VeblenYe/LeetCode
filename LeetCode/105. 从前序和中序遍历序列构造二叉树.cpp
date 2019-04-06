

/* 从前序和中序遍历序列构造二叉树 */

#include "BinaryTree.h"

#include <vector>

using std::vector;

/* 递归版思路与前同 */

TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
	vector<int> &inorder, int inStart, int inEnd) {
	if (preStart > preEnd || inStart > inEnd) return NULL;

	TreeNode *res = new TreeNode(preorder[preStart]);
	int i = inStart;
	while (inorder[i] != res->val) i++;

	res->left = build(preorder, preStart + 1, preStart + i - inStart, inorder, inStart, i - 1);
	res->right = build(preorder, preStart + i - inStart + 1, preEnd, inorder, i + 1, inEnd);

	return res;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

