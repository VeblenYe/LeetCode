
/* ��һ���Լ�ʵ�֣���Ҫ˼·��nums[i]λ��������nums[i]���Ͻ�λ�ٶ�10ȡ�࣬��λ�Ľ�λΪnums[i]���Ͻ�λ�ٳ���10 */

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

vector<int> plusOne1(vector<int> &nums) {
	vector<int> result;
	int x = 1, y;
	for (int i = nums.size() - 1; i >= 0; i--) {
		y = (nums[i] + x) % 10;		// ��ǰλ
		x = (nums[i] + x) / 10;		// ��λ
		result.push_back(y);
	}

	if (x != 0)		// ѭ�����������н�λ������1
		result.push_back(x);

	reverse(result.begin(), result.end());	// ԭ���������ǵ��õ�

	return result;
}


/* ����˼·������ô��н�λ�����Ǿͽ��м��㣬����ֱ�ӷ��� */

vector<int> plusOne2(vector<int> &digits) {

	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] < 9) {
			digits[i]++;
			return digits;
		}
		digits[i] = 0;
	}

	digits.insert(digits.begin(), 1);	// �������Ľ�λ
	return digits;

}
