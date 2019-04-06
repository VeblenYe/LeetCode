

/* 从中序和后序遍历序列构建二叉树 */

#include "BinaryTree.h"

#include "LeetCode.h"

/* 递归版思路，我们通过后序遍历的最后一个元素确定当前的根元素，再通过中序遍历划分出左子树和右子树，递归地进行创建 */

TreeNode *build(vector<int> &inorder, int b1, int e1, vector<int> &postorder, int b2, int e2) {
	if (b1 > e1 || b2 > e2) return NULL;
	TreeNode *res = new TreeNode(postorder[e2]);
	int i = b1;
	while (inorder[i] != res->val) i++;
	res->left = build(inorder, b1, i - 1, postorder, b2, b2 + i - b1 - 1);	// i是从b1开始累加的
	res->right = build(inorder, i + 1, e1, postorder, b2 + i - b1, e2 - 1);
	return res;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
