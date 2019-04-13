
#include "LeetCode.h"


/*
 * 根据STL中的next_permutation算法
 * 先从尾向头找出两个元素*i和*ii，满足*i < *ii
 * 然后再从尾找出元素*j，满足*i < *j，将*i和*j交换，
 * 再将ii之后的元素倒置即得到下一排列
 */
void nextPermutation(vector<int> &nums) {
	if (nums.empty() || nums.size() == 1)
		return;

	auto first = nums.begin();
	auto last = nums.end();

	auto i = last;
	--i;
	while (true) {
		auto ii = i;
		--i;
		if (*i < *ii) {
			auto j = last;
			while (!(*i < *--j));
			iter_swap(i, j);
			reverse(ii, last);
			return;
		}
		if (i == first) {
			reverse(first, last);
			return;
		}
	}
}
