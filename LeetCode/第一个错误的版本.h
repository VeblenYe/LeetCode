#pragma once


/* 第一个错误的版本 */

bool isBadVersion(int n) {
	return true;
}

// 递归版

int helper(long long p, long long q) {
	if (p < q) {
		long long mid = (p + q) / 2;
		if (isBadVersion(mid))
			return helper(p, mid);
		else
			return helper(mid + 1, q);
	}
	else
		return p;
}
int firstBadVersion1(int n) {
	return helper(1, n);
}

// 迭代版
int firstBadVersion2(int n) {
	int left = 1;
	int right = n;
	while (left < right) {
		auto mid = left + (right - left) / 2;	// 注意这里的中点计算
		if (isBadVersion(mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
