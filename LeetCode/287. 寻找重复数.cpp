

#include "LeetCode.h"


// 该方法思路与寻找环形链表中的开始节点相同


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
