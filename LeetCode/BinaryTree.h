#pragma once


/* ��������㶨�� */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
	
};