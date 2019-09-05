

#include "LeetCode.h"


// 这是一道典型的动态规划问题，其动态方程为dp[i][j] = dp[i-1][j] + dp[i][j-1]
// 由此可知我们仅需要两个数就可以求出下一个数，不需要完整的数组，进行空间性能优化


int uniquePaths(int m, int n) {
	vector<int> ivec(n, 1);
	for (int i = 1; i < m; ++i)	// 这里主要是先把每一行的值求出来，可以举例子逐步更新
		for (int j = 1; j < n; ++j)
			ivec[j] += ivec[j - 1];
	return ivec.back();
}

