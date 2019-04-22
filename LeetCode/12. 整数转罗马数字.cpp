
#include "LeetCode.h"


/* 
 * ˼·���г������������ֵ���ϺͶ�Ӧ������
 * ��������ÿ�μ�ȥ�ȵ�ǰ����С�������������
 * �����������������ϼ�Ϊ��
 */
string intToRoman(int num) {
	vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	vector<string> reps = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	string res;
	for (int i = 0; i < 13; i++) {
		while (values[i] <= num) {
			num -= values[i];
			res += reps[i];
		}
	}
	return res;
}
