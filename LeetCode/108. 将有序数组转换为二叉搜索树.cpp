

/* ����������ת��Ϊ�߶�ƽ����������� */

#include "BinarySearchTree.h"
#include <vector>

using std::vector;

/* ˼·�����������λ����Ϊ���ڵ㼴�� */

TreeNode* helper(vector<int> &nums, int p, int q) {
	if (p > q) return nullptr;
	int mid = (p + q) >> 1;
	auto t = new TreeNode(nums[mid]);
	t->left = helper(nums, p, mid - 1);
	t->right = helper(nums, mid + 1, q);
	return t;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return helper(nums, 0, nums.size() - 1);
}
