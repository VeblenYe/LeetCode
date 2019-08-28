

#include "LeetCode.h"


// ����������ת����γ�������������飬��Сֵ���ǵڶ��������������Ԫ�أ��ö��ַ�ȷ����Сֵ


int findMin(vector<int> &nums) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = left;
	
	// ȷʵ��ת����ѭ��
	while (nums[right] < nums[left]) {
		// ��ʱright���ǵڶ�����������Ԫ�ص�λ��
		if (right - left == 1)
			return nums[right];

		mid = (left + right) >> 1;
		
		if (nums[left] < nums[mid])
			left = mid;
		else
			right = mid;
	}
	return nums[mid];
}
