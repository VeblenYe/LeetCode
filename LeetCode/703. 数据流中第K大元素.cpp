

/* ��һ���������е�k����� */

/* 
 * ͨ����˵�������������ش洢���ݻ�����Ҫͬʱִ�����������롢ɾ���ȶಽ������
 * ����������������ݽṹ��һ���ܺõ�ѡ�� 
 * 
 * Ȼ����������С�Ѻ����Ķ�
 */


#include "LeetCode.h"



class KthLargest {
public:
	KthLargest(int k, vector<int> &nums) : kth(k) {
		init(nums, kth);
	}

	int add(int val) {
		if (pq.size() < kth) {
			pq.push(val);
		}
		else if (pq.top() < val) {
			pq.pop();
			pq.push(val);
		}
		return pq.top();
	}
private:
	void init(vector<int> &nums, int k) {
		if (nums.empty()) {
			pq.push(INT_MIN);
			return;
		}
		int i;
		int limit = (k < nums.size()) ? k : nums.size();
		for (i = 0; i < limit; ++i)
			pq.push(nums[i]);
		for(; i < nums.size(); ++i)
			if (pq.top() < nums[i]) {
				pq.pop();
				pq.push(nums[i]);
			}
	}
	int kth;
	priority_queue<int, vector<int>, greater<int>> pq;
};
