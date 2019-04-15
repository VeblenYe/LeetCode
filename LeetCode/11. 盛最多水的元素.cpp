

#include "LeetCode.h"

/*
 * �����õ��˶�̬�滮�������ı��ʽ: area = min(height[i], height[j]) * (j - i) 
 * ʹ������ָ�룬ֵС��ָ�������ƶ��������ͼ�С�������ռ� 
 * ��Ϊ���ȡ����ָ��ľ�����ֵС��ֵ�˻������ֵ���ֵ�����ƶ�������һ����С��
 * �������������һ������һ��С�ڵ���ֵС��ֵ��������һ����С��
 * ������Ҫ��������������ֵ���ָ�벻������ֵС��ָ�������ƶ�����
 */
int maxArea(vector<int> &height) {
	int maxArea = 0;
	int l = 0;
	int r = height.size() - 1;
	while (l < r) {
		int w = r - l;
		int h = height[l] < height[r] ? height[l++] : height[r--];
		maxArea = max(maxArea, h * w);
	}
	return maxArea;
}
