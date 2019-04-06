
/* 存在重复 */

#include <vector>
#include <algorithm>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::sort;

/* 思路一，我们可以利用set容器内不存在重复元素的特性，将nums中的元素拷贝到set容器中，
如果set的大小小于nums的size，则存在重复元素，时间复杂度为O(n)，然而只能打败一半的人 */

bool containsDuplicate1(vector<int> &nums) {
	unordered_set<int> s;
	s.insert(nums.begin(), nums.end());
	
	if (s.size() == nums.size())
		return false;
	else
		return true;
}

/* 思路二，将数组进行排序，然后遍历数组 */
bool containsDuplicate2(vector<int> &nums) {
	sort(nums.begin(), nums.end());
	for (int i = 1; i != nums.size(); i++)
		if (nums[i] == nums[i - 1]) return true;
	return false;
}
