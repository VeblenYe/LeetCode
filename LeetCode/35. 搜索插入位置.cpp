

#include "LeetCode.h"


int searchInsert(vector<int> &nums, int target) {
	if (nums.empty())
		return 0;

	int l = 0;
	int r = nums.size();
	while (l < r) {
		int mid = (l + r) / 2;
		if (nums[mid] < target)
			// ����������ѭ������Ϊǰ�պ󿪣���������ų�nums[mid]
			l = ++mid;
		else if (target < nums[mid])
			// ���������ﲻ���Լ�
			r = mid;
		else
			return mid;
	}
	return l;
}
