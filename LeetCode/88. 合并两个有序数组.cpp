
/* 合并两个有序数组 */


#include <vector>


using std::vector;

/* 思路一，由小到大排序，缺点，需要最后删除末尾的零 */

void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	
	int i = 0, j = 0;
	int k = 0;

	while (k < m && j < n) {
		if (nums1[i] <= nums2[j]) {
			i++;
			k++;
		}
		else {
			nums1.insert(nums1.begin() + i, nums2[j]);
			i++;
			j++;
		}
	}

	if (j < n)
		nums1.insert(nums1.begin() + i, nums2.begin() + j, nums2.end());

	nums1.resize(m + n);
	return;
}

/* 思路二：从大到小排序 */
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	int count = m + n - 1;
	m--; n--;
	while (m > 0 && n > 0)
		nums1[count--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	while (n > 0)
		nums1[count--] = nums2[n--];
}

