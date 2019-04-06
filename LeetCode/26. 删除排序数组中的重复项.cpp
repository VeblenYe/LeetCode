


/* 本质是去重问题，但是这时的数组已经有序，我们可以利用这点：快慢指针！！
令i初始指向数组的第一个元素，然后用j遍历数组，将找的的与i不同的数插入到i+1的位置，
遍历完全部数组后，前i+1个数均为不同的数，而i+1之后的数都为重复的数，全部擦除即可 */

#include <vector>

using std::vector;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty())	// 当输入为空向量时，直接返回0
		return 0;

	int i, j;

	i = j = 0;
	while (++j < nums.size()) {
		if (nums[i] != nums[j])
			nums[++i] = nums[j];
	}
	return i + 1;
}
