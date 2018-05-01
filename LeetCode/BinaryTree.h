#pragma once


/* 二叉树结点定义 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
	
};
