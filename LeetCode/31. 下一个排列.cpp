                                                                                                                
#include "LeetCode.h"


/*
 * 根据STL中的next_permutation算法
 * 先从尾向头找出两个元素*i和*ii，满足*i < *ii，这样才会有下一排列，如果没有，说明完全逆序，直接reverse即可
 * 然后再从尾找出元素*j，满足*i < *j，将*i和*j交换，因为从后向前为降序，这里的*j是最接近*i并且大于*i的数
 * 再将ii之后的元素倒置即得到下一排列，最后的倒置是为了将更改后的i后的元素按升序排列，而按原来的搜索方法，i后的元素是
 * 降序排列，即使交换了i和j也如此，我们只需倒置即可
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
