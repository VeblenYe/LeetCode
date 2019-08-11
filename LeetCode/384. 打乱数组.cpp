

#include "LeetCode.h"


class Solution {
public:
	Solution(vector<int> &nums) {
		o_nums = nums;
		s_nums = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return o_nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		random_device r;
		default_random_engine e(r());
		uniform_int_distribution<unsigned> u;
		int diff = s_nums.size();
		for (int i = diff - 1; i > 0; --i) {
			using std::swap;
			swap(s_nums[i], s_nums[u(e, (0, i))]);
		}
		return s_nums;
	}
private:
	vector<int> o_nums;
	vector<int> s_nums;
};
