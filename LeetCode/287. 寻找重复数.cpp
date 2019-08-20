

#include "LeetCode.h"


int findDuplicate(vector<int> &nums) {
	int res = 0;
	for (int fast = 0; res != fast || fast == 0;) {
		res = nums[res];
		fast = nums[nums[fast]];
	}
	//cout << res;
	for (int i = 0; res != i; i = nums[i]) {
		res = nums[res];
	}
	return res;
}
