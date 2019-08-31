
/* �������Ĳ�α��� */

#include "BinaryTree.h"

#include "LeetCode.h"

/* ���ö����Ƚ��ȳ�ʵ�� */

vector<vector<int>> levelOrder(TreeNode *root) {
	vector<vector<int>> result;
	if (!root) return result;
	queue<TreeNode *> qt;
	auto x = root;
	qt.push(x);
	for (int level = 0; !qt.empty(); ++level) {
		result.push_back({});
		for (int n = qt.size(); n > 0; --n) {	// ��һ�μ�����Ϊ�ò���ӵ�е�Ԫ�ظ���
			x = qt.front();
			result[level].push_back(x->val);
			qt.pop();
			if (x->left) qt.push(x->left);
			if (x->right) qt.push(x->right);
		}
	}
	return result;
}
