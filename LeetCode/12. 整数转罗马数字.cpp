
#include "LeetCode.h"


/* 
 * 思路，列出所有罗马数字的组合和对应的整数
 * 从整数中每次减去比当前整数小的最大罗马数字
 * 将所有罗马数字整合即为答案
 */
string intToRoman(int num) {
	vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	vector<string> reps = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	string res;
	for (int i = 0; i < 13; i++) {
		while (values[i] <= num) {
			num -= values[i];
			res += reps[i];
		}
	}
	return res;
}
