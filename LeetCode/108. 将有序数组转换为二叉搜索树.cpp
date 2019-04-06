

/* 将有序数组转换为高度平衡二叉搜索树 */

#include "BinarySearchTree.h"
#include "LeetCode.h"

/* 思路，将数组的中位数作为根节点即可 */

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
