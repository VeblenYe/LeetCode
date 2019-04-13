
#include "LeetCode.h"


/*
 * ����STL�е�next_permutation�㷨
 * �ȴ�β��ͷ�ҳ�����Ԫ��*i��*ii������*i < *ii
 * Ȼ���ٴ�β�ҳ�Ԫ��*j������*i < *j����*i��*j������
 * �ٽ�ii֮���Ԫ�ص��ü��õ���һ����
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
