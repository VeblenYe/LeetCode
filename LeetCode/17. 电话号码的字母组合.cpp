
#include "LeetCode.h"


/*
 * ˼·��ֱ�����������ϵĸ�����Ȼ�����һ����ĸ������ĸֱ�ӷ���
 */
vector<string> letterCombinations(string digits) {
	if (digits.empty())
		return {};

	unordered_map<char, string> number { {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
									   {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
									   {'8', "tuv"}, {'9', "wxyz"} };

	int n = 1;
	for (auto i : digits)
		n *= number[i].size();

	vector<string> res(n, "");
	for (auto i : digits) {
		auto s = number[i];
		n /= s.size();
		for (int i = 0; i < res.size(); ++i)
			res[i].push_back(s[(i / n) % s.size()]);
	}

	return res;
}
