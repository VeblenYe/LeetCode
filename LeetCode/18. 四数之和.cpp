

#include "LeetCode.h"


/* 与三数之和的思路是一样的，无非多了一层循环 */
vector<vector<int>> fourSum(vector<int> &nums, int target) {
	auto size = nums.size();
	if (size < 4)
		return {};

	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int i1 = 0; i1 < size - 3;) {
		for (int i2 = i1 + 1; i2 < size - 2;) {
			for (int i3 = i2 + 1, i4 = size - 1; i3 < i4;) {
				if (nums[i3] + nums[i4] == target - nums[i1] - nums[i2]) {
					res.push_back({ nums[i1], nums[i2], nums[i3], nums[i4] });
					while (i3 < i4 && nums[i3] == nums[++i3]);
					while (i3 < i4 && nums[i4] == nums[--i4]);
				} else if (nums[i3] + nums[i4] < target - nums[i1] - nums[i2]) {
					while (i3 < i4 && nums[i3] == nums[++i3]);
				} else {
					while (i3 < i4 && nums[i4] == nums[--i4]);
				}
			}
			while (i2 < size - 2 && nums[i2] == nums[++i2]);
		}
		while (i1 < size - 3 && nums[i1] == nums[++i1]);
	}

}
