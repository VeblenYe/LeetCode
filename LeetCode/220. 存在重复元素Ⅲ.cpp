
/* 存在重复Ⅲ：给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，
使 nums [i] 和 nums [j] 的绝对差值最大为 t，并且 i 和 j 之间的绝对差值最大为 ķ。*/

#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;
using std::make_pair;
using std::abs;
using std::sort;

/* 思路：这里既关注了键值和坐标值，我们就需要将两者都保存，使用pair可以同时保存两个数据，
排序后，进行遍历查找 */

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
	vector<pair<int, int>> vec;
	for (int i = 0; i < nums.size(); i++)
		vec.push_back(make_pair(nums[i], i));
	sort(vec.begin(), vec.end());
	for (int i = 0; i < nums.size(); i++) {
		int j = i + 1;
		while (j < nums.size() && (vec[j].first - vec[i].first) <= t) {
			if (abs(vec[j].second - vec[i].second) <= k) return true;
			j++;
		}
	}
	return false;
}
