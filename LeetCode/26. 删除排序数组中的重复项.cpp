


/* ������ȥ�����⣬������ʱ�������Ѿ��������ǿ���������㣺����ָ�룡��
��i��ʼָ������ĵ�һ��Ԫ�أ�Ȼ����j�������飬���ҵĵ���i��ͬ�������뵽i+1��λ�ã�
������ȫ�������ǰi+1������Ϊ��ͬ��������i+1֮�������Ϊ�ظ�������ȫ���������� */

#include <vector>

using std::vector;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty())	// ������Ϊ������ʱ��ֱ�ӷ���0
		return 0;

	int i, j;

	i = j = 0;
	while (++j < nums.size()) {
		if (nums[i] != nums[j])
			nums[++i] = nums[j];
	}
	return i + 1;
}
