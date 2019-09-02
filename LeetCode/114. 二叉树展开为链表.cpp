

#include "BinarySearchTree.h"


void flatten(TreeNode *root) {
	while (root) {
		if (root->left) {
			// ����������������������������ҽڵ�
			auto most_right = root->left;
			while (most_right->right)
				most_right = most_right->right;
			// �����ڵ��Һ����Ƶ����ҽڵ��Һ��Ӵ�
			most_right->right = root->right;
			// �ƶ����������������ڵ��Һ���
			root->right = root->left;
			// ���������ÿ�
			root->left = nullptr;
		}
		// �ƶ����ҽڵ����չ��
		root = root->right;
	}

}
