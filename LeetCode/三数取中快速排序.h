#pragma once


/*
 * ����ȡ�п��������һ�ֺõ�ģ��ʵ��
 * ʵ�ַ�����ά������������l��r��lָ���������pivot��Ԫ��λ�ã�rָ�����ҵ���pivot��Ԫ�ص���һλ�ã���ʼ���ܲ����㣩
 * ��������
 * �����ǰԪ�ر�pivotС������l����λ�ã�����l��cur��ǰ����
 * �����ǰԪ�ر�pivot������r����λ�ã�ֻ��r���ˣ���Ϊ���ܱ�֤��������Ԫ��һ��С��pivot,
 * ��������п��ܵķֶ�[first, l)����С��pivot��[l, cur)��������pivot��[cur, r)��������[r, last)��������pivot,
 * ������ɺ�ķֶ�[first, l)����С��pivot��[l, r)��������pivot, [r, last)��������pivot
 * ʵ���ŵ㣬����Ҫ����Ԫ��λ���ݹ����ʱ��pivot��ȵ�Ԫ�ز��ٽ�����������
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
