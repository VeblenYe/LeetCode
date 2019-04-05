#pragma once


#include <vector>
#include <algorithm>


using namespace std;

/*
 * 三数之和，a+b+c = 0 -> a+b = -c
 * 外层循环定位目标c
 * 内层循环找出等于c的a与b的不同组合
 */
vector<vector<int>> threeSum(vector<int> &nums) {
	if (nums.size() < 3)
		return {};

	vector<vector<int>> res;
	sort(nums.begin(), nums.end());

	auto size = nums.size();
	for (int cur = 0; cur < size - 2;) {
		for (int left = cur + 1, right = size - 1; left < right; ) {
			if (nums[left] + nums[right] == -nums[cur]) {
				res.push_back({ nums[cur], nums[left], nums[right] });
				while (left < right && nums[left] == nums[++left]);		// 去除与该解相同的a
				while (left < right && nums[right] == nums[--right]);	// 去除与该解相同的b
			}
			else if (nums[left] + nums[right] < -nums[cur])
				while (left < right && nums[left] == nums[++left]);
			else
				while (left < right && nums[right] == nums[--right]);
		}
		while (cur < size - 2 && nums[cur] == nums[++cur]);
	}
	return res;
}
