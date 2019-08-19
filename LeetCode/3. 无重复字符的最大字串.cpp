

#include "LeetCode.h"


int lengthOfLongestSubstring(string s) {
	vector<int> v(128, 0);
	int t = 0;
	int ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		t = max(t, v[s[i]]);
		ans = max(ans, i - t + 1);
		v[s[i]] = i + 1;
	}
	return ans;
}
