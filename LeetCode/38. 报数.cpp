
#include "LeetCode.h"


string countAndSay(int n) {
	if (n <= 0) return "";
	string res = "1";
	while (--n) {
		string cur = "";
		for (int i = 0; i < res.length(); i++) {
			int count = 1;
			while (i + 1 < res.length() && res[i] == res[i + 1]) {
				++count;
				++i;
			}
			cur += to_string(count) + res[i];
		}
		res = cur;
	}
	return res;
}
