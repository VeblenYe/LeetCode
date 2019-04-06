
/* ����֮�� */

#include "LeetCode.h"


/* �����ⷨ����û�м�ֵ */
vector<int> twoSum1(vector<int> &nums, int target) {

	for (int i = 0; i < nums.size(); i++)
		for (int j = i + 1; j < nums.size(); j++)
			if ((nums[i] + nums[j]) == target)
				return {i, j};

}


/* hash����ⷨ�����ţ����ֻ��ҪO(n)��ʱ�䣬˼·�Ƕ��ڵ�ǰ��Ԫ��nums[i]������������ҵ�Ԫ��nums[j]��
ʹ nums[j] = target-nums[i]�������������Ҫ�ҵ�Ԫ�أ�����O(1)��ʱ�����ҵ�����������Ǿ���Ҫ����Hash���飬
Ҳ����unordered_map��ʵ�� */

vector<int> twoSum2(vector<int> &nums, int target) {
	unordered_map<int, int> m;

	/*
	for (int i = 0; i != nums.size(); i++)
		m[nums[i]] = i;
	*/

	for (int i = 0; i < nums.size(); i++) {
		int t = target - nums[i];
		if (m.count(t) /*&& m[t] != i*/)	// �Ҳ���������Ϊû�б����룬������
			return { i, m[t] };
		m[nums[i]] = i;		// ���õ���Ҫ�ҵ���û�б����룬�������ǻ�����
	}

}
