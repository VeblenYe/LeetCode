

#include "LeetCode.h"


bool searchMatrix(vector<vector<int>> &matrix, int target) {
	if (matrix.empty() || matrix[0].empty())
		return false;

	auto row = matrix.size();
	auto col = matrix[0].size();

	for (int i = 0, j = col - 1; i < row && j >= 0; ) {
		if (matrix[i][j] < target)
			++i;
		else if (target < matrix[i][j])
			--j;
		else
			return true;
	}
	return false;
}