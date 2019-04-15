

#include "LeetCode.h"


int threeSumClosest(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());
	auto min = INT_MIN;
	for (int i = 0; i < nums.size(); ++i) {
		int l = i + 1;
		int r = nums.size() - 1;
		while (l < r) {
			int sum = nums[i] + nums[l] + nums[r];
			if (abs(sum - target) < abs(min - target))
				min = sum;
			if (min == target)
				return min;
			if (sum < target)
				++l;
			else
				--r;
		}
	}
	return min;
}
