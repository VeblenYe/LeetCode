

#include "LeetCode.h"


/*
 * 这道题和2. 两数相加十分相像，所以思路基本一致，这里的技巧是直接使用carry作为各位计算
 * 的和，并且循环判断条件也进行了一些改变，这样在最后一位运算产生进位时也能一并处理而不
 * 需要在循环外判断。
 */


string addStrings(string num1, string num2) {
	string res;
	int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
	while (i >= 0 || j >= 0 || carry > 0) {
		if (i >= 0)
			carry += num1[i--] - '0';
		if (j >= 0)
			carry += num2[j--] - '0';
		res = (char)(carry % 10 + '0') + res;	// 取余得到该位数值
		carry /= 10;	// 除10获取下一位数值
	}
	return res;
}
