
#include "LeetCode.h"

int strStr(string haystack, string needle) {
	if (needle.empty()) return 0;
	int i, j, k;
	auto m = haystack.size();
	auto n = needle.size();
	for (int i = 0; i < m; i++) {
		for (j = i, k = 0; k < n && haystack[j] == needle[k]; j++, k++);
		if (k > 0 && k == n) return i;
	}
	return -1;
}
