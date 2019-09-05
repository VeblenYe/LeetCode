


#include "LeetCode.h"


// �����ÿ�����ж��Ƿ�Ϊ�������Դ��ۼӵ�n������Ч��ʮ�ֵ��£������ÿռ任ʱ��
// ����֮ǰ�ĳ�����2��3��5���ó���һ����������ΪҪ����õ�������Ҫȡ��������Сֵ
// ��һ��ȷ������һ���������϶�Ӧ�����õ���һ����������Ҫ�������������ʹ��˻���
// ����һ�������Դ˲��ϼ�����һ������


int nthUglyNumber(int n) {
	vector<int> ivec(n, 1);
	int i2 = 0, i3 = 0, i5 = 0;
	for (int i = 0; i < n; ++i) {
		auto tmp = min(min(ivec[i2] * 2, ivec[i3] * 3), ivec[i5] * 5);
		if (ivec[i2] * 2 == tmp)
			++i2;
		if (ivec[i3] * 3 == tmp)
			++i3;
		if (ivec[i5] * 5 == tmp)
			++i5;
		ivec[i] = tmp;
	}
	return ivec.back();
}
