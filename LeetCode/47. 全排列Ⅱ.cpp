

#include "LeetCode.h"


// 回溯 + 状态重置


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