#pragma once


/* 移动零 */

#include <vector>

using std::vector;

/* 思路一，对于当前的零元素，往后查找到第一个非零元素并与之交换，但时间复杂度过高，最坏为O(n²) */

void moveZeros1(vector<int> &nums) {
	using std::swap;
	for (int i = 0; i != nums.size(); i++) {
		if (nums[i] == 0)
			for (int j = i + 1; j != nums.size(); j++)
				if (nums[j] != 0) {
					swap(nums[i], nums[j]);
					break;
				}
	}
}

/* 思路二，快慢指针！！用一个快指针fast和一个慢指针slow来遍历数组，fast每次都自增，而slow只有碰到非零元素再自增，
当fast到达数组末尾后，令slow后的剩下元素赋值0即可，时间复杂度O(n) */

void moveZeros2(vector<int> &nums) {
	int n = nums.size();
	int slow, fast;

	slow = fast = 0;
	while (fast < n) {
		if (nums[fast] != 0)
			nums[slow++] = nums[fast];
		fast++;
	}

	while (slow < n)
		nums[slow++] = 0;
}

/* 思路三，结合思路一和思路二 */

void moveZeros3(vector<int> &nums) {
	using std::swap;
	for (int i = 0, j = 0; i < nums.size(); i++)
		if (nums[i])
			swap(nums[i], nums[j++]);
}
