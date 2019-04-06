
#include "LeetCode.h"


int romanToInt(string s) {
	unordered_map<char, int> map{ {'I', 1}, {'V' , 5}, {'X' , 10}, {'L' , 50}, {'C' , 100}, {'D' , 500}, {'M' , 1000} };
	int sum = 0;
	for (auto beg = s.begin(); beg != s.end(); ++beg) {
		// ��ǰԪ�رȺ�һԪ��С�����ȼ���ǰԪ�أ���һ��ѭ���м��Ϻ�һԪ��
		if (beg + 1 != s.end() && map[*beg] < map[*(beg + 1)])
			sum -= map[*beg];
		else
			sum += map[*beg];
	}
	return sum;
}
