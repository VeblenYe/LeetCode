
#include "LeetCode.h"

int numSquares(int n) {
	if (n == 0)
		return 0;

	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j * j + i <= n; ++j)
			dp[j * j + i] = min(dp[i] + 1, dp[j * j + i]);

	return dp.back();
}
