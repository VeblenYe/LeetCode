
/* 加一，自己实现，主要思路，nums[i]位的数就是nums[i]加上进位再对10取余，该位的进位为nums[i]加上进位再除以10 */

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

vector<int> plusOne1(vector<int> &nums) {
	vector<int> result;
	int x = 1, y;
	for (int i = nums.size() - 1; i >= 0; i--) {
		y = (nums[i] + x) % 10;		// 当前位
		x = (nums[i] + x) / 10;		// 进位
		result.push_back(y);
	}

	if (x != 0)		// 循环结束若还有进位则增加1
		result.push_back(x);

	reverse(result.begin(), result.end());	// 原来的数组是倒置的

	return result;
}


/* 大佬思路，如果该处有进位，我们就进行计算，否则直接返回 */

vector<int> plusOne2(vector<int> &digits) {

	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] < 9) {
			digits[i]++;
			return digits;
		}
		digits[i] = 0;
	}

	digits.insert(digits.begin(), 1);	// 处理最后的进位
	return digits;

}
