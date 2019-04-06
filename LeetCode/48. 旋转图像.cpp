
/* 旋转图像 */

#include "LeetCode.h"

/* 思路一，一个 n * n 矩阵中，坐标为(i, j)的元素，旋转后坐标为(j, n - i - 1)，
每次循环四个元素 */

void rotate1(vector<vector<int>> &matrix) {
	int n = matrix.size();
	for (int i = 0; i < n / 2; i++)
		// 启发：如果顺时针交换比较麻烦，可以试试逆时针
		for (int j = i; j < n - i - 1; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = temp;
		}

}

/* 实现二，大神写的好简洁 */

void rotate2(vector<vector<int>> &matrix) {
	if (matrix.size() <= 1) return;

	for (int n = 1; n < matrix.size(); ++n) {
		for (int m = 0; m < n; ++m) {
			int tmp = matrix[n][m];
			matrix[n][m] = matrix[m][n];
			matrix[m][n] = tmp;
		}
	}
	for (int n = 0; n < matrix.size(); ++n) {
		for (int m = 0; m < matrix.size() / 2; ++m) {
			int tmp = matrix[n][matrix.size() - m - 1];
			matrix[n][matrix.size() - m - 1] = matrix[n][m];
			matrix[n][m] = tmp;
		}
	}
}
