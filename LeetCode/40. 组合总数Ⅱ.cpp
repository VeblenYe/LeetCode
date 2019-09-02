


#include "LeetCode.h"


void generateCombination(vector<vector<int>> &cmb, vector<int> &curCmb, vector<int> cand, int target, int start) {
	if (target == 0) {
		cmb.push_back(curCmb);
		return;
	}

	for (int i = start; i < cand.size() && (target - cand[i]) >= 0; ++i) {
		if (i > start && cand[i] == cand[i - 1])
			continue;
		curCmb.push_back(cand[i]);
		generateCombination(cmb, curCmb, cand, target - cand[i], i + 1);
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
