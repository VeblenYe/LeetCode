


#include "LeetCode.h"
#include "BinarySearchTree.h"


void aux(vector<vector<int>> &path, vector<int> &cur, TreeNode *root, int sum) {
	sum -= root->val;
	cur.push_back(root->val);	//��ѹ�뵱ǰ�ڵ�

	// ����Ҷ�ڵ㲢��·������ȣ��򱣴��·��
	if (sum == 0 && !root->left && !root->right) {
		path.push_back(cur);
		return;
	}

	if (root->left) {
		aux(path, cur, root->left, sum);	// ����ڵ����·��
		cur.pop_back();	// ��ڵ������ɾ͵�����ڵ㣬����
	}
	if (root->right) {
		aux(path, cur, root->right, sum);	// ���ҽڵ����·��
		cur.pop_back();	// �ҽڵ������ɾ͵����ҽڵ㣬����
	}
	
}


vector<vector<int>> pathSum(TreeNode *root, int sum) {
	if (!root)
		return {};

	vector<vector<int>> path;
	vector<int> cur;	// �洢��ǰ·��
	aux(path, cur, root, sum);
	return path;
}
