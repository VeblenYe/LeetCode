

#include "LeetCode.h"


class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		auto size = min.size() + max.size();
		if (size & 1) {
			// 为奇数，插入最大堆
			if (!min.empty() && min[0] < num) {
				// 先插入右边最小堆，重新建堆
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				// 得到最小数，保证该数一定比最小堆的都小
				num = min[0];

				// 从最小堆中删除
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			// 再插入左边最大堆，重新建堆
			max.push_back(num);
			push_heap(max.begin(), max.end());
		} else {
			// 为偶数，插入最小堆
			if (!max.empty() && num < max[0]) {
				// 先插入最大堆，重新建堆
				max.push_back(num);
				push_heap(max.begin(), max.end());

				// 得到最大数，保证该数一定比最大堆的都大
				num = max[0];

				// 从最大堆中删除
				pop_heap(max.begin(), max.end());
				max.pop_back();
			}
			// 再插入右边最小堆，重新建堆
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
	}

	double findMedian() {
		auto size = min.size() + max.size();
		if (size & 1)
			return min[0];
		else
			return (min[0] + max[0]) / 2.0;
	}
	
private:
	vector<int> min;
	vector<int> max;
};
