#pragma once


/* �ַ����еĵ�һ��Ψһ�ַ� */

#include <string>
#include <set>

using std::string;
using std::set;

/* ˼·һ����set��¼�ظ����ַ� */

int firstUniqChar1(string s) {
	set<char> sc;
	for (int i = 0; i < s.size(); i++) {
		for (int j = i + 1; j <= s.size(); j++) {
			if (j == s.size() && sc.count(s[i]) != 1) 
				return i;
			if (s[i] == s[j]) {
				sc.insert(s[i]);
				break;
			}
		}
	}
	return -1;
}

/* ˼·��������set */

int firstUniqChar2(string s) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[i] == s[j] && i != j) break;
			if (j == s.size() - 1) return i;
		}
	}
	return -1;
}

/* ˼·���������������飬��һ���¼Ԫ�س��ֵĸ��� */

int firstUniqChar3(string s) {
	int cnt[26];	// �ٶ�����Сд�ַ�
	std::memset(cnt, 0, sizeof(cnt));	// ����cpp
	for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
	for (int i = 0; i < s.size(); i++)
		if (cnt[s[i] - 'a'] == 1)
			return i;
	return -1;
}
