
#include "LeetCode.h"


/* Ë¼Â·£º*/
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
