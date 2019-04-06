
/* �����ظ� */

#include "LeetCode.h"

/* ˼·һ�����ǿ�������set�����ڲ������ظ�Ԫ�ص����ԣ���nums�е�Ԫ�ؿ�����set�����У�
���set�Ĵ�СС��nums��size��������ظ�Ԫ�أ�ʱ�临�Ӷ�ΪO(n)��Ȼ��ֻ�ܴ��һ����� */

bool containsDuplicate1(vector<int> &nums) {
	unordered_set<int> s;
	s.insert(nums.begin(), nums.end());
	
	if (s.size() == nums.size())
		return false;
	else
		return true;
}

/* ˼·�����������������Ȼ��������� */
bool containsDuplicate2(vector<int> &nums) {
	sort(nums.begin(), nums.end());
	for (int i = 1; i != nums.size(); i++)
		if (nums[i] == nums[i - 1]) return true;
	return false;
}
