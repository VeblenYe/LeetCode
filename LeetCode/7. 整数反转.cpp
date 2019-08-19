

/* 颠倒整数 */

#include "LeetCode.h"

/* 自己想的垃圾思路2333333 */

int reverse1(int x) {
	bool b = true;
	if (x < 0) {
		b = false;
		x = -x;
	}
	ostringstream os;
	os << x;
	auto s = os.str();
	reverse(s.begin(), s.end());
	if (b)
		if (INT_MAX < stoll(s))
			return 0;
		else
			return stoll(s);
	else
		if (-stoll(s) < INT_MIN)
			return 0;
		else
			return -stoll(s);
}

/* 思路二，自己看吧 */
int reverse2 (int x) {
	int ans = 0;
	while (x) {
		int temp = 10 * ans + x % 10;
		if (temp / 10 != ans) // 如果溢出，则返回
			return 0;
		ans = temp;
		x /= 10;
	}
	return ans;
}
