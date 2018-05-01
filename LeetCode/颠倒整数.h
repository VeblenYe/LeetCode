#pragma once


/* �ߵ����� */

#include <climits>
#include <sstream>
#include <algorithm>

using std::ostringstream;
using std::reverse;
using std::stoll;

/* �Լ��������˼·2333333 */

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

/* ˼·�����Լ����� */
int reverse2 (int x) {
	int ans = 0;
	while (x)
	{
		int temp = 10 * ans + x % 10;
		if (temp / 10 != ans) return 0;
		ans = temp;
		x /= 10;
	}
	return ans;
}
