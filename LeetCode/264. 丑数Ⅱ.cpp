


#include "LeetCode.h"


// 如果对每个数判断是否为丑数，以此累加到n个，其效率十分低下，这里用空间换时间
// 即由之前的丑数乘2、3或5，得出下一个丑数，因为要按序得到，所以要取三个的最小值
// 而一旦确认是由一个丑数乘上对应的数得到下一个数，就需要更新这个丑数，使其乘积大
// 于下一个数，以此不断计算下一个丑数


int nthUglyNumber(int n) {
	vector<int> ivec(n, 1);
	int i2 = 0, i3 = 0, i5 = 0;
	for (int i = 0; i < n; ++i) {
		auto tmp = min(min(ivec[i2] * 2, ivec[i3] * 3), ivec[i5] * 5);
		if (ivec[i2] * 2 == tmp)
			++i2;
		if (ivec[i3] * 3 == tmp)
			++i3;
		if (ivec[i5] * 5 == tmp)
			++i5;
		ivec[i] = tmp;
	}
	return ivec.back();
}
