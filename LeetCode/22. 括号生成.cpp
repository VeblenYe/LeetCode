

#include "LeetCode.h"

/* 思路：需要用到递归，delta用于记录还有多少个左括号可用于匹配
x用于记录还有多少个左括号可用于添加，y用于记录还有多少个右括号可用于添加 */

vector<string> ans;

void f(string s, int delta, int x, int y) {
	if (x == 0 && y == 0) {
		ans.emplace_back(s);
		return;
	}
	if (delta > 0 && y > 0)
		f(s + ")", delta - 1, x, y - 1);
	if (x > 0)
		f(s + "(", delta + 1, x - 1, y);
}


vector<string> generateParenthesis(int n) {
	string s = "";
	f("", 0, n, n);
	return ans;
}
