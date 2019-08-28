

#include "LeetCode.h"


// 把一个整数减去1，再和原整数做与运算，会把该整数最右边的1变成0。
// 那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的运算。


int hammingWeight(uint32_t n) {
	unsigned int count = 0;
	while (n) {
		n &= n - 1;
		++count;
	}
	return count;
}

