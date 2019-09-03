


#include "LeetCode.h"


// 这一题的思路是从个位开始分位求1，首先要找到规律，对于个位的1，每10个数出现一次
// 对于十位的1，每100个数出现10次，以此类推
// 可以这样想，当当前数超过100时，则十位1必出现10次，当当前数小于100时，通过个位个数进行判断，但是上限为10（10~19）
// 以此类推，数n的i位来说，如果n / (i * 10)大于0，则第i位的1一定出现过n / (i * 10) * i次，此时不需要通过低位判断（低位输出0）
// 如果n / (i * 10)等于0，说明可能没有出现所有的1，则需要通过低位进行判断，其最小值为0，最大值为i


int countDigitOne(int n) {
	int count = 0;
	for (long long i = 1; i <= n; i *= 10) {
		long long divider = i * 10;
		count += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
	}
	return count;
}

