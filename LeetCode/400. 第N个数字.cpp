


#include "LeetCode.h"


// �����˼·�ǣ�����iλ�����乲��9 * i * pow��10�� i - 1��������
// �������������n���бȶԣ��Ϳ��������������
// ���ͨ����ѧ�����ж�λ��


int findNthDigit(int n) {
	int i = 1;
	while (i * pow(10, i - 1) * 9 < n) {
		n -= i * pow(10, i - 1) * 9;
		++i;
	}
	auto num = (n - 1) / i + pow(10, i - 1); // �����һ����Ϊ��1��ʼ�����������Ҫ�ҵ�������
	auto str = to_string(num);	// ת���ַ�������ȷ��λ��
	return n % i == 0 ? str[i - 1] - '0' : str[n % i - 1] - '0';
}