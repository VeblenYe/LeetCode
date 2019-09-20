

#include "LeetCode.h"


int subarraySum(vector<int> &nums, int k) {
	unordered_map<int, int> um;
	int curSum = 0;
	int count = 0;
	um[0] = 1;
	for (auto num : nums) {
		curSum += num;
		count += um.find(curSum - k) == um.end() ? 0 : um[curSum - k];
		++um[curSum];
	}
	return count;
}
