

/* ����һ���������飬����ֻ��һ��Ԫ��ֻ����һ�Σ�����Ԫ�ؾ��������Σ����ǿ���������ʱ��ͳ����ռ����ҳ������
����Ϊ�������е�ÿһ���������������ͬ������������Ϊ0�����ʣ�µ��Ǹ�����Ϊֻ����һ�ε���*/


#include "LeetCode.h"

int singleNumber(vector<int>& nums) {

	int result = 0;

	for (int i = 0; i < nums.size(); i++)
		result ^= nums[i];

	return result;
}
