#pragma once


/* 两个数组的交集Ⅱ */


#include <vector>
#include <algorithm>
#include <set>

using std::vector;
using std::multiset;
using std::sort;

/* 自己想的垃圾思路，把nums1和nums2分别存入multiset中，然后选取两个数组中较小的那个进行遍历（要是能对set遍历应该更好）
分别查找各自set中相同的元素个数，较少的那一个即是交集，然后从两个set中删除这个元素，继续遍历，时间复杂度应为O(n)，
但是函数调用带来的开销太大了，要进行优化 */

vector<int> intersect1(vector<int> &nums1, vector<int> &nums2) {
	multiset<int> s1, s2;
	s1.insert(nums1.begin(), nums1.end());
	s2.insert(nums2.begin(), nums2.end());

	vector<int> result;
	if (nums1.size() < nums2.size()) {
		for (int i = 0; i != nums1.size(); i++) {
			int n1 = s1.count(nums1[i]);
			int n2 = s2.count(nums1[i]);
			if (n1 < n2)
				result.insert(result.end(), n1, nums1[i]);
			else
				result.insert(result.end(), n2, nums1[i]);
			s1.erase(nums1[i]);
			s2.erase(nums1[i]);
		}
	}
	else {
		for (int i = 0; i != nums2.size(); i++) {
			int n1 = s1.count(nums2[i]);
			int n2 = s2.count(nums2[i]);
			if (n1 < n2)
				result.insert(result.end(), n1, nums2[i]);
			else
				result.insert(result.end(), n2, nums2[i]);
			s1.erase(nums2[i]);
			s2.erase(nums2[i]);
		}
	}

	return result;
}


/* 大佬思路，先进行排序，然后双迭代器遍历两个数组，将相同元素存入数组 */

vector<int> intersect2(vector<int> &nums1, vector<int> &nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	auto iter1 = nums1.begin();
	auto iter2 = nums2.begin();

	vector<int> result;
	while (iter1 != nums1.end() && iter2 != nums2.end()) {
		if (*iter1 < *iter2) iter1++;
		else if (*iter2 < *iter1) iter2++;
		else {
			result.push_back(*iter1);
			iter1++;
			iter2++;
		}
	}
	
	return result;
}