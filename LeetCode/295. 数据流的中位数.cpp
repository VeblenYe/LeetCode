

#include "LeetCode.h"


class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		auto size = min.size() + max.size();
		if (size & 1) {
			// Ϊ��������������
			if (!min.empty() && min[0] < num) {
				// �Ȳ����ұ���С�ѣ����½���
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				// �õ���С������֤����һ������С�ѵĶ�С
				num = min[0];

				// ����С����ɾ��
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			// �ٲ���������ѣ����½���
			max.push_back(num);
			push_heap(max.begin(), max.end());
		} else {
			// Ϊż����������С��
			if (!max.empty() && num < max[0]) {
				// �Ȳ������ѣ����½���
				max.push_back(num);
				push_heap(max.begin(), max.end());

				// �õ����������֤����һ�������ѵĶ���
				num = max[0];

				// ��������ɾ��
				pop_heap(max.begin(), max.end());
				max.pop_back();
			}
			// �ٲ����ұ���С�ѣ����½���
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
