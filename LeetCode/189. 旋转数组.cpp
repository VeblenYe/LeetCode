
/* ��ת���� */
/* ��һ���汾���Լ�������ģ���i��Ԫ������kΪ�������������(i+k)%n��ֻ��ҪO(n)��ʱ�䣬������ҪO(n)�Ķ���ռ� */

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

void rotate1(vector<int> &nums, int k) {
	
	vector<int> temp(nums.size());

	for (int i = 0; i != nums.size(); i++) {
		// N % K = N - (N / K) * K
		temp[(i + k) - ((i + k) / nums.size()) * nums.size()] = nums[i];
	}

	for (int i = 0; i != nums.size(); i++)
		nums[i] = temp[i];
}


/* �ڶ����汾�����ϵ��뷨������һ�η�ת����vector���ڶ��η�תǰk % n��Ԫ�أ������η�תʣ��Ԫ�أ�ֻ��ҪO(1)�ռ䣬
��ӿ��ٶȵĻ������Լ�дreverse */

void rotate2(vector<int> &nums, int k) {
	int n = k - (k / nums.size()) * nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + n);
	reverse(nums.begin() + n, nums.end());
}
