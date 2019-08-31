

#include "LeetCode.h"


// ˼·������ģ�⣬�Ȼ�ͼ����˼·����д����ͺܼ���


vector<int> spiralOrder(vector<vector<int>> &matrix) {
	if (matrix.empty())
		return {};

	vector<int> ans;
	int r1 = 0, r2 = matrix.size() - 1;
	int c1 = 0, c2 = matrix[0].size() - 1;
	while (r1 <= r2 && c1 <= c2) {
		for (int c = c1; c <= c2; ++c)	// ��ӡ�Ϸ�Ԫ��
			ans.push_back(matrix[r1][c]);
		for (int r = r1 + 1; r <= r2; ++r)	// ��ӡ�ҷ�Ԫ��
			ans.push_back(matrix[r][c2]);
		if (r1 < r2 && c1 < c2) {	// ���������ж��ǵ�ǰҪ��ȡ�ľ���ֻʣ��һ�л�һ��ʱ���Ͳ�����Ҫ��ӡ�·����󷽵�Ԫ��
			for (int c = c2 - 1; c > c1; --c)	// ��ӡ�·�Ԫ��
				ans.push_back(matrix[r2][c]);
			for (int r = r2; r > r1; --r)	// ��ӡ��Ԫ��
				ans.push_back(matrix[r][c1]);
		}
		// �����µĲ�
		++r1;
		--r2;
		++c1;
		--c2;
	}
	return ans;
}
