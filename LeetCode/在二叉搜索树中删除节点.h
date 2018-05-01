#pragma once


/* �ڶ�����������ɾ���ڵ� */


#include "BinarySearchTree.h"


TreeNode *deleteNode(TreeNode *root, int key) {

	if (!root) return nullptr;

	if (root->val == key) {		// �����ǰ�ڵ㼴ΪҪɾ���ڵ�
		if (root->left) {		// ��������������������������Ԫ�أ�������λ�ã��ٵݹ�����������ɾ���ڵ�
			auto next = root->left;
			while (next->right)
				next = next->right;

			next->val ^= root->val;		// ����Ҫ��ʱ������swap��֪�����У�����ֵ���Ƽ�
			root->val ^= next->val;
			next->val ^= root->val;

			root->left = deleteNode(root->left, key);
		}
		else if (root->right) {	// ���û�������������������������������������СԪ�أ�������λ�ã��ٵݹ�����������ɾ���ڵ�
			auto next = root->right;
			while (next->left)
				next = next->left;

			next->val ^= root->val;		// ����Ҫ��ʱ������swap
			root->val ^= next->val;
			next->val ^= root->val;

			root->right = deleteNode(root->right, key);
		}
		else {					// û���κ�������ֱ��ɾ��������nullptr���ݹ��
			delete root;
			return nullptr;
		}
	}
	else if (key < root->val && root->left)	// ���ҽڵ�����������
		root->left = deleteNode(root->left, key);
	else if (root->val < key && root->right)	// ���ҽڵ�����������
		root->right = deleteNode(root->right, key);

	return root;	// û���ҵ��ڵ�
}

