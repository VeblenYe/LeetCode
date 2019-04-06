
#include "LeetCode.h"


int romanToInt(string s) {
	unordered_map<char, int> map{ {'I', 1}, {'V' , 5}, {'X' , 10}, {'L' , 50}, {'C' , 100}, {'D' , 500}, {'M' , 1000} };
	int sum = 0;
	for (auto beg = s.begin(); beg != s.end(); ++beg) {
		// 当前元素比后一元素小，则先减当前元素，下一次循环中加上后一元素
		if (beg + 1 != s.end() && map[*beg] < map[*(beg + 1)])
			sum -= map[*beg];
		else
			sum += map[*beg];
	}
	return sum;
}
