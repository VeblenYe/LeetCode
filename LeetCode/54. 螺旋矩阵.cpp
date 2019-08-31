

#include "LeetCode.h"


// 思路：按层模拟，先画图理清思路，再写代码就很简单了


vector<int> spiralOrder(vector<vector<int>> &matrix) {
	if (matrix.empty())
		return {};

	vector<int> ans;
	int r1 = 0, r2 = matrix.size() - 1;
	int c1 = 0, c2 = matrix[0].size() - 1;
	while (r1 <= r2 && c1 <= c2) {
		for (int c = c1; c <= c2; ++c)	// 打印上方元素
			ans.push_back(matrix[r1][c]);
		for (int r = r1 + 1; r <= r2; ++r)	// 打印右方元素
			ans.push_back(matrix[r][c2]);
		if (r1 < r2 && c1 < c2) {	// 这里加入的判断是当前要读取的矩阵只剩下一行或一列时，就不再需要打印下方和左方的元素
			for (int c = c2 - 1; c > c1; --c)	// 打印下方元素
				ans.push_back(matrix[r2][c]);
			for (int r = r2; r > r1; --r)	// 打印左方元素
				ans.push_back(matrix[r][c1]);
		}
		// 进入新的层
		++r1;
		--r2;
		++c1;
		--c2;
	}
	return ans;
}
