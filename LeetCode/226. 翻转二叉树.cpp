

#include "BinarySearchTree.h"


// ˼·���ݹ鷭ת����


TreeNode *invertTree(TreeNode *root) {
	if (!root)
		return root;

	auto tmp = root->left;	// ��¼ԭ������
	root->left = invertTree(root->right);	// ����������תΪ������
	root->right = invertTree(tmp);	// ����������תΪԭ������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

	return root;
}
