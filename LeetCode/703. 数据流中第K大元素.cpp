

/* 求一个数据流中第k大的数 */

/* 
 * 通常来说，如果你想有序地存储数据或者需要同时执行搜索、插入、删除等多步操作，
 * 二叉搜索树这个数据结构是一个很好的选择 
 * 
 * 然而这里用最小堆好做的多
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
