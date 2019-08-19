

#include "LeetCode.h"


/*
 * ������2. �������ʮ����������˼·����һ�£�����ļ�����ֱ��ʹ��carry��Ϊ��λ����
 * �ĺͣ�����ѭ���ж�����Ҳ������һЩ�ı䣬���������һλ���������λʱҲ��һ���������
 * ��Ҫ��ѭ�����жϡ�
 */


string addStrings(string num1, string num2) {
	string res;
	int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
	while (i >= 0 || j >= 0 || carry > 0) {
		if (i >= 0)
			carry += num1[i--] - '0';
		if (j >= 0)
			carry += num2[j--] - '0';
		res = (char)(carry % 10 + '0') + res;	// ȡ��õ���λ��ֵ
		carry /= 10;	// ��10��ȡ��һλ��ֵ
	}
	return res;
}
