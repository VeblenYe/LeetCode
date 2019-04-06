
#include "LeetCode.h"

int MaxSubsequenceSum(vector<int> &A, int n) {
	int ThisSum, MaxSum;

	ThisSum = MaxSum = 0;
	for (int i = 0; i != n; i++) {
		ThisSum += A[i];

		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}
int maxProfit(vector<int> &prices) {
	if (prices.size() == 1 || prices.size() == 0)
		return 0;
	vector<int> temp;
	for (int i = 0; i != prices.size() - 1; i++)
		temp.push_back(prices[i + 1] - prices[i]);

	return MaxSubsequenceSum(temp, temp.size());
}
