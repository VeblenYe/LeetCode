#pragma once


/* ������ͺ���������й��������� */

#include "BinaryTree.h"

#include <vector>

using std::vector;

/* �ݹ��˼·������ͨ��������������һ��Ԫ��ȷ����ǰ�ĸ�Ԫ�أ���ͨ������������ֳ������������������ݹ�ؽ��д��� */

TreeNode *build(vector<int> &inorder, int b1, int e1, vector<int> &postorder, int b2, int e2) {
	if (b1 > e1 || b2 > e2) return NULL;
	TreeNode *res = new TreeNode(postorder[e2]);
	int i = b1;
	while (inorder[i] != res->val) i++;
	res->left = build(inorder, b1, i - 1, postorder, b2, b2 + i - b1 - 1);	// i�Ǵ�b1��ʼ�ۼӵ�
	res->right = build(inorder, i + 1, e1, postorder, b2 + i - b1, e2 - 1);
	return res;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
