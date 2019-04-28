

#include "LeetCode.h"

/* ˼·����Ҫ�õ��ݹ飬delta���ڼ�¼���ж��ٸ������ſ�����ƥ��
x���ڼ�¼���ж��ٸ������ſ�������ӣ�y���ڼ�¼���ж��ٸ������ſ�������� */

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
