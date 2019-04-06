
/* ÿ���ڵ������ָ���û�м��� */

#include "BinaryTree.h"
#include <queue>

using std::queue;

/* ˼·һ�����ǿ����ò�α��� */
void connect(TreeNode *root) {
	if (!root) return;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		for (int n = q.size(); n > 0; n--) {
			auto x = q.front();
			q.pop();
			if (n != 1)
				x->next = q.front();
			else
				x->next = nullptr;
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
		}
	}
}
