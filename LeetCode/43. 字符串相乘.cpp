

#include "LeetCode.h"


/*
 * 字符串相乘有两个思路，一个是模拟竖式乘法，这里需要借助字符串相加进行配合；
 * 这里实现的是第二的思路，也就是平行乘法，首先要清楚，一个m*n位的运算，其结果小于等于
 * m+n位，而结果中第k位（1<=k<=m+n)的数值由第一个乘数中的第i位和第二个乘数中的第j位以及
 * 结果原第k位上的数值决定（其中k = i + j + 1)，而第k位最终的运算结果还可能对k-1位产生
 * 进位。了解以上内容后，我们就可以通过二重循环，直接求得结果中每个位的数值，这里需要注意
 * 的是，我们需要从最低位向最高位进行计算，这样才能保证向k-1进行进位时不至于又发生新的进位
 */


string multiply(string num1, string num2) {
	if (num1[0] == '0' || num2[0] == '0')
		return "0";

	string res(num1.size() + num2.size(), '0');

	for (int i = num1.size() - 1; i >= 0; --i) {
		int n1 = num1[i] - '0';
		for (int j = num2.size() - 1; j >= 0; --j) {
			int n2 = num2[j] - '0';
			int sum = (res[i + j + 1] - '0') + n1 * n2;
			res[i + j + 1] = '0' + sum % 10;
			res[i + j] += sum / 10;
		}
	}

	for (int i = 0; i < res.size(); ++i)
		if (res[i] != '0')
			return res.substr(i, res.size());

	return "0";
}

