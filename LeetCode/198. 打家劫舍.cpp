

#include "LeetCode.h"


int rob(vector<int> &nums) {
	if (nums.empty())
		return 0;
	if (nums.size() == 1)
		return nums[0];
	vector<int> dp{ nums[0], max(nums[0], nums[1]) };
	for (int i = 2; i < nums.size(); ++i)
		dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
	return dp.back();
}


int rob1(vector<int> &nums) {
	int rob = 0, notRob = 0, n = nums.size();
	for (int i = 0; i < n; ++i) {
		int preRob = rob, preNotRob = notRob;
		rob = preNotRob + nums[i];
		notRob = max(preRob, preNotRob);
	}
	return max(rob, notRob);
}
