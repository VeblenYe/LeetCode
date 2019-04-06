

/* �������������� */

/* ������������ʱ������˼��һ���������⣺

����ȷ��һЩ�������Ӹýڵ�����������Ѱ�Ҵ���
�����ʹ����Щ�����ͽڵ㱾���ֵ������ʲôӦ���Ǵ��ݸ����ӽڵ�Ĳ�����
����𰸶��ǿ϶��ģ���ô�볢��ʹ�� ���Զ����¡� �ĵݹ�����������⡣

�������������˼�����������е�����һ���ڵ㣬�����֪�����ӽڵ�Ĵ𰸣����ܼ�����ýڵ�Ĵ���
������ǿ϶��ģ���ô ���Ե����ϡ� �ĵݹ������һ������Ľ��������*/

#include "BinaryTree.h"

#include "LeetCode.h"

/* �Ե����� */

int maxDepth(TreeNode *root) {
	if (!root) return 0;

	int l = maxDepth(root->left);
	int r = maxDepth(root->right);

	return max(l, r) + 1;
}

/* �Զ����� */

int answer = 0;
int maxDepth(TreeNode *root, int depth) {
	if (!root) return 0;
	
	if (!root->left && !root->right)
		answer = max(answer, depth);

	maxDepth(root->left, depth + 1);
	maxDepth(root->right, depth + 1);
}
