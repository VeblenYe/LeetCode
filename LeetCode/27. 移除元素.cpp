
#include "LeetCode.h"

int removeElement(vector<int> &nums, int val) {
	int n = nums.size();
	int slow = 0;
	int fast = 0;
	while (fast < n) {
		if (nums[fast] != val)
			nums[slow++] = nums[fast];
		++fast;
	}
	return slow;
}