

#include "LeetCode.h"


int searchInsert(vector<int> &nums, int target) {
	if (nums.empty())
		return 0;

	int l = 0;
	int r = nums.size();
	while (l < r) {
		int mid = (l + r) / 2;
		if (nums[mid] < target)
			// 避免陷入死循环，因为前闭后开，这里可以排除nums[mid]
			l = ++mid;
		else if (target < nums[mid])
			// 后开所以这里不用自减
			r = mid;
		else
			return mid;
	}
	return l;
}
