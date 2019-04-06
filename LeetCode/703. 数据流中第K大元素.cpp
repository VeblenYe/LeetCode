

/* ��һ���������е�k����� */

/* ͨ����˵�������������ش洢���ݻ�����Ҫͬʱִ�����������롢ɾ���ȶಽ������
����������������ݽṹ��һ���ܺõ�ѡ�� */


#include <vector>

using std::vector;


struct Node {
	int val;
	int cnt;
	Node *left;
	Node *right;
	Node(int x) : val(x), cnt(1), left(nullptr), right(nullptr) {}
};

class KthLargest {
public:
	// ���캯������
	KthLargest(int k, vector<int> nums) : kth(k) {
		if (nums.empty())
			root = NULL;
		else
			root = new Node(nums[0]);
		for (auto i = 1; i < nums.size(); i++) {
			auto cur = root;
			auto pre = cur;
			while (cur) {
				pre = cur;
				pre->cnt++;
				if (nums[i] <= cur->val)
					cur = cur->left;
				else
					cur = cur->right;
			}
			if (nums[i] <= pre->val)
				pre->left = new Node(nums[i]);
			else
				pre->right = new Node(nums[i]);
		}
	}

	// ��ӹ�������
	int add(int val) {
		if (!root) {
			root = new Node(val);
			return find(root, kth);
		}
		auto cur = root;
		auto pre = cur;
		while (cur) {
			pre = cur;
			pre->cnt++;
			if (val <= cur->val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (val <= pre->val)
			pre->left = new Node(val);
		else
			pre->right = new Node(val);

		return find(root, kth);
	}

	int find(Node *root, int kth) {
		if (!root) return NULL;
		if (!root->right) {
			if (kth == 1) return root->val;
			return find(root->left, kth - 1);
		}
		else {
			if (kth == 1) return find(root->right, 1);
			if (kth == root->right->cnt + 1) return root->val;
			if (kth <= root->right->cnt) return find(root->right, kth);
			if (kth > root->right->cnt) return find(root->left, kth - 1 - root->right->cnt);
		}
	}

	Node *getRoot() const { return root; }
private:
	int kth;
	Node *root;
};
