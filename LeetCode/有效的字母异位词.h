#pragma once


/* ��Ч��ĸ����λ�� */

#include <string>
#include <algorithm>

using std::string;
using std::sort;

/* ˼·һ�������Ƚ��Ƿ���� */

bool isAnagram1(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

/* ˼·������һ��Ψһ�ַ���࣬�������鲢��¼���ʳ��ִ������ٽ��бȽ� */

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
