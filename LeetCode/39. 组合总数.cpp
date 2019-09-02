

#include "LeetCode.h"


// 思路：这题元素可以重复使用，但是也可以通过回溯、剪枝解决


// 这里的参数start实际上就是一个状态向量，它表明start之前的元素均不可再次访问，以避免重复的组合，
// 但元素可以重复使用，所以传入下一个组合的仍是当前的start
void generateCombination(vector<vector<int>> &cmb, vector<int> &curCmb, vector<int> cand, int target, int start) {
	if (target == 0) {
		cmb.push_back(curCmb);
		return;
	}

	for (int i = start; i < cand.size() && (target - cand[i]) >= 0; ++i) {
		curCmb.push_back(cand[i]);
		generateCombination(cmb, curCmb, cand, target - cand[i], i);
		curCmb.pop_back();
	}
}


vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
	if (candidates.empty())
		return {};

	sort(candidates.begin(), candidates.end());
	vector<vector<int>> cmb;
	vector<int> curCmb;
	generateCombination(cmb, curCmb, candidates, target, 0);
	return cmb;
}
