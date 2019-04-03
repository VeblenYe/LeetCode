#pragma once


/*
 * 三数取中快速排序的一种好的模板实现
 * 实现方法，维护两个迭代器l和r，l指向最左等于pivot的元素位置，r指向最右等于pivot的元素的下一位置（初始可能不满足）
 * 遍历区间，如果当前元素比pivot小，则与l交换位置，并且l与cur均前进，
 * 如果当前元素比pivot大，则于r交换位置，只有r后退，因为不能保证换回来的元素一定小于pivot,
 * 程序进行中可能的分段[first, l)——小于pivot，[l, cur)——等于pivot，[cur, r)——乱序，[r, last)——大于pivot,
 * 分组完成后的分段[first, l)——小于pivot，[l, r)——等于pivot, [r, last)——大于pivot
 * 实现优点，不需要将主元移位，递归分组时与pivot相等的元素不再进入排序区间
 */


template <typename ForwardIterator>
void swap(ForwardIterator lhs, ForwardIterator rhs) {
	auto t = *lhs;
	*lhs = *rhs;
	*rhs = t;
}


template <typename T>
const T &median(const T &a, const T &b, const T &c) {
	if (a < b)
		if (b < c)
			return b;
		else if (a < c)
			return c;
		else
			return a;
	if (a < c)
		return a;
	if (b < c)
		return b;
	else
		return c;
}


template <typename RandomAccessIterator>
void QuickSort(RandomAccessIterator first, RandomAccessIterator last) {
	if (first < last) {
		auto pivot = median(*first, *(first + (last - first) / 2), *(last - 1));
		auto l = first;
		auto r = last;
		auto cur = first;
		while (cur < r) {
			if (*cur < pivot) {
				::swap(cur, l);
				++cur;
				++l;
			}
			else if (pivot < *i) {
				--r;
				::swap(cur, r);
			}
			else ++cur;
		}

		QuickSort(first, l);
		QuickSort(r, last);
	}
}
