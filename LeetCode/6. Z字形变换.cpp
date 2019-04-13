
#include "LeetCode.h"


/* 思路：直接根据输出行遍历字符串，确定输出行字符在字符串中的位置 
 * 对于每一个全元素列，其行i当前列k元素的索引位置为k(2n-2)+i;
 * 对于每一个非全元素列（每行该列的元素个数为1），其行i当前列k元素的索引位置为(k+1)(2n-2)-i
 */
string convert(string s, int numRows) {
	if (numRows == 1)
		return s;

	auto size = s.size();
	int cycleLen = 2 * numRows - 2;
	string res;
	for(int i = 0; i < numRows; ++i)
		for (int j = 0; j + i < size; j += cycleLen) {
			res += s[j + i];
			if (i != 0 && i != numRows - 1 && j + cycleLen - i < size)
				res += s[j + cycleLen - i];
		}
	
	return res;
}
