


#include "LeetCode.h"


// 这里的思路是，对于i位数，其共有9 * i * pow（10， i - 1）个数字
// 根据这个数据与n进行比对，就可以跳过许多数据
// 最后通过数学规律判断位置


int findNthDigit(int n) {
	int i = 1;
	while (i * pow(10, i - 1) * 9 < n) {
		n -= i * pow(10, i - 1) * 9;
		++i;
	}
	auto num = (n - 1) / i + pow(10, i - 1); // 这里减一是因为从1起始，这个数就是要找的完整数
	auto str = to_string(num);	// 转成字符串便于确定位数
	return n % i == 0 ? str[i - 1] - '0' : str[n % i - 1] - '0';
}