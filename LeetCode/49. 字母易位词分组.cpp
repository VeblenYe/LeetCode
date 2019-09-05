

#include "LeetCode.h"


vector<vector<string>> groupAnagrams(vector<string> &strs) {
	
	vector<int> prime{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };

	vector<vector<string>> res;
	for (auto str : strs) {
		int key = 1;
		for (auto ch : str)
			key *= prime[ch - 'a'];
	}
}