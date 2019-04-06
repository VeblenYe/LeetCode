
/* 验证回文字符串 */

#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::tolower;
using std::isalnum;
using std::reverse;

/* 思路一，忽略s中的标点字符，将字母数字记录到vector中，然后判断其头尾是否相等 */

bool isPalindrome(string s) {
	if (s.empty() || s.size() == 1) return true;

	vector<char> cvec;
	for (int i = 0; i < s.size(); i++) {
		if (isalnum(s[i]))
			cvec.push_back(tolower(s[i]));
	}
	for (int i = 0, j = cvec.size() - 1; i < j; i++, j--)
		if (cvec[i] != cvec[j]) return false;

	return true;
}
