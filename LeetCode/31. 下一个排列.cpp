                                                                                                                
#include "LeetCode.h"


/*
 * ����STL�е�next_permutation�㷨
 * �ȴ�β��ͷ�ҳ�����Ԫ��*i��*ii������*i < *ii�������Ż�����һ���У����û�У�˵����ȫ����ֱ��reverse����
 * Ȼ���ٴ�β�ҳ�Ԫ��*j������*i < *j����*i��*j��������Ϊ�Ӻ���ǰΪ���������*j����ӽ�*i���Ҵ���*i����
 * �ٽ�ii֮���Ԫ�ص��ü��õ���һ���У����ĵ�����Ϊ�˽����ĺ��i���Ԫ�ذ��������У�����ԭ��������������i���Ԫ����
 * �������У���ʹ������i��jҲ��ˣ�����ֻ�赹�ü���
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
