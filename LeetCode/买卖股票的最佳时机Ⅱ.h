#pragma once


/* 买卖股票的最佳时机Ⅱ */

#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/* 思路，这道题很简单，就是算出股票前后一天的差，如果差大于零我们就累加到一个变量中，最后这个变量即为能获得的
最大利润 */

int maxProfit(vector<int> &prices) {
	int sum = 0;

	for (int i = 1; i < prices.size(); i++) {
		sum += max(prices[i] - prices[i - 1], 0);
	}

	return sum;
}
