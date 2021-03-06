
#include "LeetCode.h"


int divide(int dividend, int divisor) {
	long ans = 0;
	long up = fabs(dividend);
	long down = fabs(divisor);
	while (up >= down) {
		long count = 1;
		long base = down;
		while (up > (base << 1)) {
			count <<= 1;
			base <<= 1;
		}
		ans += count;
		up -= base;
	}
	ans = ((dividend < 0) ^ (divisor < 0)) ? -ans : ans;
	return (ans > INT_MAX || ans < INT_MIN) ? INT_MAX : ans;
}
