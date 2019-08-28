

#include "BinarySearchTree.h"


// 递归判断，注意这里是完整的子树，而不是一部分


bool aux(TreeNode *s, TreeNode *t) {
	if (!t && !s)
		return true;
	return s && t && s->val == t->val && aux(s->left, t->left) && aux(s->right, t->right);
}


bool isSubtree(TreeNode *s, TreeNode *t) {
	if (!s && !t)
		return true;
	if (!s && t)
		return false;
	return aux(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

