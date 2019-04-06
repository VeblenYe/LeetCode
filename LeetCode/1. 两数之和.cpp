
/* 两数之和 */

#include <vector>
#include <unordered_map>


using std::unordered_map;
using std::vector;


/* 暴力解法，并没有价值 */
vector<int> twoSum1(vector<int> &nums, int target) {

	for (int i = 0; i < nums.size(); i++)
		for (int j = i + 1; j < nums.size(); j++)
			if ((nums[i] + nums[j]) == target)
				return {i, j};

}


/* hash数组解法，这个牛逼了只需要O(n)的时间，思路是对于当前的元素nums[i]，如果我们能找到元素nums[j]，
使 nums[j] = target-nums[i]，则这就是我们要找的元素，想在O(1)的时间里找到这个数，我们就需要借助Hash数组，
也就是unordered_map来实现 */

vector<int> twoSum2(vector<int> &nums, int target) {
	unordered_map<int, int> m;

	/*
	for (int i = 0; i != nums.size(); i++)
		m[nums[i]] = i;
	*/

	for (int i = 0; i < nums.size(); i++) {
		int t = target - nums[i];
		if (m.count(t) /*&& m[t] != i*/)	// 找不到自身！因为没有被读入，真神奇
			return { i, m[t] };
		m[nums[i]] = i;		// 不用担心要找的数没有被读入，两个数是互补的
	}

}
