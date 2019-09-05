

#include "LeetCode.h"


// 懂这里的思路了，就是动态规划，其中v中的每一个元素记录的都是该字符最后一次出现的位置
// t表示当前的不重复子串的起始位置，而v[s[i]]表示以s[i]这个字符结尾的不重复字串的最长长度
// ans记录整个字符串中最长不重复子串的长度


int lengthOfLongestSubstring(string s) {
	vector<int> v(128, 0);
	int t = 0;
	int ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		t = max(t, v[s[i]]);	// 这里的max是必要的，因为下一个字符有可能没有重复，则t=0，结论错误，t应该从最后一个重复的字符开始
		ans = max(ans, i - t + 1);	// i - t + 1就是当前字符减去起始字符的长度
		v[s[i]] = i + 1;	// 这里的i+1是记录s[i]最后出现的位置，因为下标从0开始，所以这里加1
	}
	return ans;
}
