#pragma once


/* ��֤�����ַ��� */

#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::tolower;
using std::isalnum;
using std::reverse;

/* ˼·һ������s�еı���ַ�������ĸ���ּ�¼��vector�У�Ȼ���ж���ͷβ�Ƿ���� */

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
