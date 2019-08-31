

/* 对称二叉树，即原树与镜像树一致 */

#include "BinaryTree.h"

bool Symmetric(TreeNode *p, TreeNode *q) {

	if (!p && !q) return true;	// 如果两个结点都为空，则对称
	if (!p || !q) return false;	// 如果两个结点有一个为空，则不对称
	if (p->val != q->val) return false;	// 如果两个结点键值不同，则不对称

	return Symmetric(p->left, q->right) && Symmetric(p->right, q->left);	/* 判断左节点的左子树和右节点的右子树
																			左节点的右子树和右节点的左子树是否对称
																			因为镜像翻转后，它们的位置会就此交换 */
}

bool isSymmetric(TreeNode *root) {

	if (!root) return true;
	return Symmetric(root->left, root->right);

}

