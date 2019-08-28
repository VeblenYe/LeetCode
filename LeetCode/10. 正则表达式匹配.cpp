
#include "LeetCode.h"

// 含有备忘录优化的版本，也就是自顶向下动态规划，但是需要额外空间
bool dp(const string &s, const string &p, int i, int j, map<pair<int, int>, bool> &memo) {
	if (memo.find({ i, j }) != memo.end())
		return memo[{i, j}];

	if (j == p.size())
		return i == s.size();

	bool first = false;
	bool ans = false;

	if (i < s.size() && (p[j] == s[i] || p[j] == '.'))
		first = true;

	if (j <= p.size() - 2 && p[j + 1] == '*')
		ans = dp(s, p, i, j + 2, memo) || (first && dp(s, p, i + 1, j, memo));
	else
		ans = first && dp(s, p, i + 1, j + 1, memo);

	memo[{i, j}] = ans;

	return ans;
}


// 不带备忘录的递归版本，时间复杂度略高，但空间复杂度较低
bool dp(const string &s, const string &p, int i, int j) {
	if (j == p.size())	// 当模式串分析完成时，判断输入串是否也分析完成
		return i == s.size();

	auto firstMatch = i < s.size() && (p[j] == s[i] || p[j] == '.');	// 本次匹配的结果

	if (j <= p.size() - 2 && p[j + 1] == '*')	// 如果后一个模式为'*'，当前可能匹配0次或1次
		// 若当前匹配0次，则直接跳过'*'，并且当前字符的匹配需要到下一次判定；
		// 若当前匹配1次，则不更新模式，直接进入下一字符
		return dp(s, p, i, j + 2) || (firstMatch && dp(s, p, i + 1, j));
	else
		// 减而治之
		return firstMatch && dp(s, p, i + 1, j + 1);
}


bool isMatch(string s, string p) {
	map<pair<int, int>, bool> memo;
	return dp(s, p, 0, 0, memo);
}
