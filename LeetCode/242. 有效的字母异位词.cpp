
/* 有效字母的异位词 */

#include <string>
#include <algorithm>

using std::string;
using std::sort;

/* 思路一，排序后比较是否相等 */

bool isAnagram1(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

/* 思路二，跟一个唯一字符差不多，读入数组并记录单词出现次数，再进行比较 */

bool isAnagram2(string s, string t) {
	if (s.size() != t.size())
		return false;
	int a[260] = { 0 }, b[260] = { 0 };
	int i;
	for (i = 0; i<s.size(); ++i)
	{
		a[(int)s[i]] += 1;
		b[(int)t[i]] += 1;
	}
	for (i = 0; i<s.size(); ++i)
	{
		if (a[(int)s[i]] != b[(int)s[i]])
			return false;
	}
	return true;
}
