


#include "LeetCode.h"
#include "BinarySearchTree.h"


void aux(vector<vector<int>> &path, vector<int> &cur, TreeNode *root, int sum) {
	sum -= root->val;
	cur.push_back(root->val);	//先压入当前节点

	// 到达叶节点并且路径和相等，则保存该路径
	if (sum == 0 && !root->left && !root->right) {
		path.push_back(cur);
		return;
	}

	if (root->left) {
		aux(path, cur, root->left, sum);	// 到左节点查找路径
		cur.pop_back();	// 左节点查找完成就弹出左节点，回溯
	}
	if (root->right) {
		aux(path, cur, root->right, sum);	// 到右节点查找路径
		cur.pop_back();	// 右节点查找完成就弹出右节点，回溯
	}
	
}


vector<vector<int>> pathSum(TreeNode *root, int sum) {
	if (!root)
		return {};

	vector<vector<int>> path;
	vector<int> cur;	// 存储当前路径
	aux(path, cur, root, sum);
	return path;
}
