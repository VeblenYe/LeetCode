

#include "LeetCode.h"


// 回溯 + 状态重置


// 我认为全排列和组合最大的不同是，排序后，组合只需向前（向右）看（否则会出现重复项），所以组合可以只用一个变量标识
// 而全排列不管有无排序则还需要向后（向左）看，而全排列却需要一个vector来判断


void generatePermutation(vector<vector<int>> &per, vector<int> &curPer, vector<int> &nums, vector<bool> &visited) {
	if (curPer.size() == nums.size()) {
		per.push_back(curPer);
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (!visited[i]) {
			// 对于46题而言，主要是加排序和验证是否跟上一个已访问元素是否相同
			if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
				continue;
			curPer.push_back(nums[i]);
			visited[i] = true;
			generatePermutation(per, curPer, nums, visited);
			curPer.pop_back();
			visited[i] = false;
		}
	}
}


vector<vector<int>> permuteUnique(vector<int> &nums) {
	if (nums.empty())
		return {};

	sort(nums.begin(), nums.end());
	vector<vector<int>> per;
	vector<int> curPer;
	vector<bool> visited(nums.size(), false);
	generatePermutation(per, curPer, nums, visited);
	return per;
}