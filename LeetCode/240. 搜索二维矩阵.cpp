
#include "LeetCode.h"

bool searchMatrix(vector<vector<int>> &matrix, int target) {
	if (matrix.size() == 0)
		return false;
	int m = 0;
	int n = matrix[0].size() - 1;
	while (m < matrix.size() && n >= 0)
	{
		if (matrix[m][n] < target) ++m;
		else if (target < matrix[m][n]) --n;
		else return true;
	}
	return false;
}
