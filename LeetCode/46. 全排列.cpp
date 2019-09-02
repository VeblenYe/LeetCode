

#include "LeetCode.h"


// »ØËİ + ×´Ì¬ÖØÖÃ


void generatePermutation(vector<vector<int>> &per, vector<int> &curPer, vector<int> &nums, vector<bool> &visited) {
	if (curPer.size() == nums.size()) {
		per.push_back(curPer);
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (!visited[i]) {
			curPer.push_back(nums[i]);
			visited[i] = true;
			generatePermutation(per, curPer, nums, visited);
			curPer.pop_back();
			visited[i] = false;
		}
	}
}


vector<vector<int>> permute(vector<int> &nums) {
	if (nums.empty())
		return {};

	vector<vector<int>> per;
	vector<int> curPer;
	vector<bool> visited(nums.size(), false);
	generatePermutation(per, curPer, nums, visited);
	return per;
}