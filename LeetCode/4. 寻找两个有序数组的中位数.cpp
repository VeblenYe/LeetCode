

#include "LeetCode.h"


// 思路主要是归并


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	vector<int> temp(nums1.size() + nums2.size());

	merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), temp.begin());

	return temp.size() % 2 == 0 ?
		(temp[(temp.size() - 1) / 2] + temp[(temp.size() + 1) / 2]) / 2.0 : temp[temp.size() / 2];
}
