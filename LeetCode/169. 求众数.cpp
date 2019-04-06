
#include "LeetCode.h"

int majorityElement(vector<int> &nums) {
	int cur;
	int count = 0;
	auto size = nums.size();
	for (int i = 0; i < size; ++i) {
		if (count == 0)
			cur = nums[i];
		if (nums[i] == cur)
			++count;
		else
			--count;
	}
	return cur;
}
