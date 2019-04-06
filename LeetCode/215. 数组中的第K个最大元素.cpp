
#include "LeetCode.h"

void swap(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

int partition(vector<int> &k, int low, int high) {
	int point;

	int m = low + (high - low) / 2;

	if (k[low] > k[high]) {
		swap(k, low, high);
	}
	if (k[m] > k[high]) {
		swap(k, m, high);
	}
	if (k[m] > k[low]) // 使得low存放中间的值
	{
		swap(k, m, low);
	}

	point = k[low];

	while (low < high) {
		while (low < high && k[high] >= point) //过滤掉比low大的
			high--;
		k[low] = k[high];

		while (low < high && k[low] <= point)
			low++;
		k[high] = k[low];
	}

	k[low] = point;

	return low;
}

int randomized_select(vector<int> & nums, int p, int r, int i) {
	if (p == r)
		return nums[p];

	auto q = partition(nums, p, r);
	int k = q - p + 1;
	if (i == k)
		return nums[q];
	else if (i < k)
		return randomized_select(nums, p, q - 1, i);
	else
		return randomized_select(nums, q + 1, r, i - k);
}

int findKthLargest(vector<int> & nums, int k) {
	return randomized_select(nums, 0, nums.size() - 1, nums.size() - k + 1);
}
