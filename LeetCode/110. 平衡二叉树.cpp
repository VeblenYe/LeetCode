
/* ƽ������� */

#include "BinarySearchTree.h"
#include "LeetCode.h"

/* ˼·�������ǰ�ڵ������������ȣ����������һ���򷵻�false����������ж�
���������Ƿ����Ϊƽ������� */
// �Ż����Ե����ϣ�ÿ���ڵ�ֻ����һ��

bool aux(TreeNode *root, int &depth) {
	if (!root) {
		depth = 0;
		return true;
	}

	int left, right;
	if (aux(root->left, left) && aux(root->right, right)) {
		if (abs(left - right) <= 1) {
			depth = 1 + max(left, right);
			return true;
		}
	}

	return false;
}

bool isBalanced(TreeNode *root) {
	if (!root) return true;
	int depth = 0;
	return aux(root, depth);
}
