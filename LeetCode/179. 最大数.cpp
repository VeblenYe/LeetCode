

#include "LeetCode.h"


// 思路：自定义比较规则


string largestNumber(vector<int> &nums) {
	vector<string> svec;

	for (auto num : nums)
		svec.push_back(to_string(num));

	sort(svec.begin(), svec.end(), [](const string &a, const string &b) {
		auto ab = a + b;
		auto ba = b + a;
		return ba < ab;
		});

	if (svec[0] == "0")
		return "0";

	string res;
	for (auto str : svec)
		res += str;

	return res;
}
