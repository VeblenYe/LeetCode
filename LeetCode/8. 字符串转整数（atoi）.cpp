

#include "LeetCode.h"


int myAtoi1(string str) {
	if (str.empty()) return 0;

	for (int i = 0; i < str.size(); ++i) {
		auto c = str[i];
		if (!std::isdigit(c) && c != '+' && c != '-')
			str.erase(str.begin() + i);
	}

	return std::stoi(str);
}


// hhhh第一次写就通过了，最近还是有长进的
int myAtoi2(string str) {
	if (str.empty()) return 0;

	int i;
	for (i = 0; i < str.size() && std::isspace(str[i]); ++i);

	if (i == str.size()) return 0;

	int sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = str[i++] == '+' ? 1 : -1;

	if (!std::isdigit(str[i])) return 0;

	long long result = 0;
	for (; i < str.size() && std::isdigit(str[i]); ++i) {
		result = result * 10 + str[i] - '0';
		if (result > INT_MAX)
			return sign == 1 ? INT_MAX : INT_MIN;
	}
	return (int)(result * sign);
}
