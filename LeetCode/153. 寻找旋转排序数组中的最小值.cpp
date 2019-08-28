

#include "LeetCode.h"


// 排序数组旋转后会形成两个有序的数组，最小值就是第二个有序数组的首元素，用二分法确定最小值


int findMin(vector<int> &nums) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = left;
	
	// 确实旋转进入循环
	while (nums[right] < nums[left]) {
		// 此时right就是第二有序数组首元素的位置
		if (right - left == 1)
			return nums[right];

		mid = (left + right) >> 1;
		
		if (nums[left] < nums[mid])
			left = mid;
		else
			right = mid;
	}
	return nums[mid];
}
