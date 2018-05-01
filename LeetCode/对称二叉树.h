#pragma once


/* �Գƶ����� */

#include "BinaryTree.h"

bool Symmetric(TreeNode *p, TreeNode *q) {

	if (!p && !q) return true;	// ���������㶼Ϊ�գ���Գ�
	if (!p || !q) return false;	// ������������һ��Ϊ�գ��򲻶Գ�
	if (p->val != q->val) return false;	// �����������ֵ��ͬ���򲻶Գ�
	return Symmetric(p->left, q->right) && Symmetric(p->right, q->left);	/* �ж���ڵ�����������ҽڵ��������
																			��ڵ�����������ҽڵ���������Ƿ�Գ� */
}

bool isSymmetric(TreeNode *root) {

	if (!root) return true;
	return Symmetric(root->left, root->right);

}

