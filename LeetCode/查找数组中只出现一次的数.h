#pragma once


/* 给定一个整数数组，其中只有一个元素只出现一次，其余元素均出现两次，我们可以在线性时间和常数空间下找出这个数
方法为对数组中的每一个数进行异或，则相同的数都会相消为0，最后剩下的那个数即为只出现一次的数*/


#include <vector>

using std::vector;

int singleNumber(vector<int>& nums) {

	int result = 0;

	for (int i = 0; i < nums.size(); i++)
		result ^= nums[i];

	return result;
}
