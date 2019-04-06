
/* ���л��ͷ����л������� */

#include "BinaryTree.h"

#include "LeetCode.h"


/* ���л���BFS�������õ���ƽʱû��ô�õ���ostringstream��˳�������intת��Ϊstring�����⣬����NULL�����#����ʶ */

string serialize(TreeNode *root) {
	ostringstream out;
	queue<TreeNode *> q;
	if (root) q.push(root);
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		if (x) {
			out << x->val << ' ';
			q.push(x->left);
			q.push(x->right);
		}
		else
			out << "# ";
	}
	return out.str();	// ���ص�
}

/* �����л�����ϰ��istringstream��������ʱ����" "��ֹͣ */

TreeNode *deserialize(string data) {
	if (data.empty()) return nullptr;
	istringstream in(data);
	queue<TreeNode *> q;
	string val;
	in >> val;
	TreeNode *root = new TreeNode(std::stoi(val));
	auto cur = root;
	q.push(cur);
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		if (!(in >> val)) break;
		if (val != "#") {
			cur = new TreeNode(std::stoi(val));
			q.push(cur);
			t->left = cur;
		}
		if (!(in >> val)) break;
		if (val != "#") {
			cur = new TreeNode(std::stoi(val));
			q.push(cur);
			t->right = cur;
		}
	}
	return root;
}

