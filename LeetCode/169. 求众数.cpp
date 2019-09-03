
#include "LeetCode.h"

int majorityElement(vector<int> &nums) {
	if (nums.empty())
		return 0;
	int cur = nums[0];
	int count = 0;
	auto size = nums.size();
	for (int i = 1; i < size; ++i) {
		if (count == 0)
			cur = nums[i];
		if (nums[i] == cur)
			++count;
		else
			--count;
	}
	return cur;
}
