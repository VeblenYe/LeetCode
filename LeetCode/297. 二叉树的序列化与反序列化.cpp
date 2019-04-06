
/* 序列化和反序列化二叉树 */

#include "BinaryTree.h"

#include <string>
#include <queue>
#include <sstream>


using std::string;
using std::queue;
using std::istringstream;
using std::ostringstream;


/* 序列化，BFS，这里用到了平时没怎么用到的ostringstream，顺利解决了int转换为string的问题，并在NULL处添加#来标识 */

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
	return out.str();	// 划重点
}

/* 反序列化，复习了istringstream读入数据时会在" "处停止 */

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

