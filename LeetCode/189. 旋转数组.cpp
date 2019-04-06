
/* 旋转数组 */
/* 第一个版本是自己想出来的，第i个元素右移k为后所在坐标就是(i+k)%n，只需要O(n)的时间，但是需要O(n)的额外空间 */

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

void rotate1(vector<int> &nums, int k) {
	
	vector<int> temp(nums.size());

	for (int i = 0; i != nums.size(); i++) {
		// N % K = N - (N / K) * K
		temp[(i + k) - ((i + k) / nums.size()) * nums.size()] = nums[i];
	}

	for (int i = 0; i != nums.size(); i++)
		nums[i] = temp[i];
}


/* 第二个版本是网上的想法，即第一次翻转整个vector，第二次翻转前k % n个元素，第三次翻转剩下元素，只需要O(1)空间，
想加快速度的话可以自己写reverse */

void rotate2(vector<int> &nums, int k) {
	int n = k - (k / nums.size()) * nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + n);
	reverse(nums.begin() + n, nums.end());
}
