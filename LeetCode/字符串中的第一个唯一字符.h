#pragma once


/* 字符串中的第一个唯一字符 */

#include <string>
#include <set>

using std::string;
using std::set;

/* 思路一，用set记录重复的字符 */

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

/* 思路二，不用set */

int firstUniqChar2(string s) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[i] == s[j] && i != j) break;
			if (j == s.size() - 1) return i;
		}
	}
	return -1;
}

/* 思路三，遍历两遍数组，第一遍记录元素出现的个数 */

int firstUniqChar3(string s) {
	int cnt[26];	// 假定都是小写字符
	std::memset(cnt, 0, sizeof(cnt));	// 查阅cpp
	for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
	for (int i = 0; i < s.size(); i++)
		if (cnt[s[i] - 'a'] == 1)
			return i;
	return -1;
}
