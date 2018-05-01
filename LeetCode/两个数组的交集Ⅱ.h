#pragma once


/* ��������Ľ����� */


#include <vector>
#include <algorithm>
#include <set>

using std::vector;
using std::multiset;
using std::sort;

/* �Լ��������˼·����nums1��nums2�ֱ����multiset�У�Ȼ��ѡȡ���������н�С���Ǹ����б�����Ҫ���ܶ�set����Ӧ�ø��ã�
�ֱ���Ҹ���set����ͬ��Ԫ�ظ��������ٵ���һ�����ǽ�����Ȼ�������set��ɾ�����Ԫ�أ�����������ʱ�临�Ӷ�ӦΪO(n)��
���Ǻ������ô����Ŀ���̫���ˣ�Ҫ�����Ż� */

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


/* ����˼·���Ƚ�������Ȼ��˫�����������������飬����ͬԪ�ش������� */

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