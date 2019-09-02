

#include "LeetCode.h"


// ˼·������Ԫ�ؿ����ظ�ʹ�ã�����Ҳ����ͨ�����ݡ���֦���


// ����Ĳ���startʵ���Ͼ���һ��״̬������������start֮ǰ��Ԫ�ؾ������ٴη��ʣ��Ա����ظ�����ϣ�
// ��Ԫ�ؿ����ظ�ʹ�ã����Դ�����һ����ϵ����ǵ�ǰ��start
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
