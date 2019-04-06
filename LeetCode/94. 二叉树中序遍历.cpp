
#include "BinaryTree.h"

#include <vector>
#include <stack>

using std::vector;
using std::stack;

/* ������� */

/* �ݹ�� */

void inDfs(TreeNode *root, vector<int> &ivec) {
	if (!root) return;
	inDfs(root->left, ivec);
	ivec.push_back(root->val);
	inDfs(root->right, ivec);
}

vector<int> inorderTraversal1(TreeNode* root) {
	vector<int> ivec;
	inDfs(root, ivec);
	return ivec;
}



/* ������һ�����������˳��Ϊ�����У��ҡ�
�侭��˼·Ϊ����ǰ�ڵ������ӽڵ�ʱ������ǰ�ڵ�ѹջ���������ӽڵ���Ϊ��ǰ����
��ǰ�ڵ������ӽڵ�ʱ����ʾ���������ѱ�����ɣ���ʱ���ʵ�ǰ�ڵ㣬�������ӽڵ���Ϊ��ǰ�ڵ㡣*/

vector<int> inorderTraversal2(TreeNode* root) {
	if (!root) return {};
	stack<TreeNode *> s;
	vector<int> ivec;
	auto p = root;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			ivec.push_back(p->val);
			s.pop();
			p = p->right;
		}
	}
	return ivec;
}

/* ������� */

void goAlongLeftBranch(TreeNode *root, vector<int> &ivec, stack<TreeNode *> &s) {
	while (root) {
		s.push(root);
		root = root->left;
	}
}

vector<int> inorderTraversal3(TreeNode *root) {
	if (!root) return {};
	vector<int> ivec;
	stack<TreeNode *> s;
	auto x = root;

	while (true) {
		goAlongLeftBranch(x, ivec, s);
		if (s.empty()) break;
		x = s.top();
		ivec.push_back(x->val);
		s.pop();
		x = x->right;
	}

	return ivec;
}
