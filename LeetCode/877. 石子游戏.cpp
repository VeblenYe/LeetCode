

#include "LeetCode.h"


bool stoneGame(vector<int> &piles) {
	vector<vector<pair<int, int>>> dp;
	vector<pair<int, int>> row;
	row.resize(piles.size());
	for (auto i = 0; i < piles.size(); ++i) {
		dp.push_back(row);
		dp[i][i] = { piles[i], 0 };
	}

	for (auto l = 1; l < piles.size(); ++l) {
		for (auto i = 0; i < piles.size() - l; ++i) {
			auto j = i + l;
			auto left = piles[i] + dp[i + 1][j].second;
			auto right = piles[j] + dp[i][j - 1].second;
			if (left < right) {
				dp[i][j].first = right;
				dp[i][j].second = dp[i][j - 1].first;
			} else {
				dp[i][j].first = left;
				dp[i][j].second = dp[i + 1][j].first;
			}
		}
	}
	return dp[0][piles.size() - 1].first > dp[0][piles.size() - 1].second;
}
