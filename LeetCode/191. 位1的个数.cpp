

#include "LeetCode.h"


// ��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұߵ�1���0��
// ��ôһ�������Ķ����Ʊ�ʾ���ж��ٸ�1���Ϳ��Խ��ж��ٴ����������㡣


int hammingWeight(uint32_t n) {
	unsigned int count = 0;
	while (n) {
		n &= n - 1;
		++count;
	}
	return count;
}

