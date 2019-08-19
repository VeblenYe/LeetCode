

/* 二叉搜索树的最深公共祖先 */


#include "BinarySearchTree.h"

/* 思路和二叉树差不多，不过利用了一些二叉搜索树的性质 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || root == p || root == q)
		return root;

	if ((p->val <= root->val) && (root->val < q->val) ||
		(root->val < p->val) && (q->val <= root->val))
		return root;

	if (p->val <= root->val) 
		return lowestCommonAncestor(root->left, p, q);
	else 
		return lowestCommonAncestor(root->right, p, q);
}
