
/* ��תͼ�� */

#include "LeetCode.h"

/* ˼·һ��һ�� n * n �����У�����Ϊ(i, j)��Ԫ�أ���ת������Ϊ(j, n - i - 1)��
ÿ��ѭ���ĸ�Ԫ�� */

void rotate1(vector<vector<int>> &matrix) {
	int n = matrix.size();
	for (int i = 0; i < n / 2; i++)
		// ���������˳ʱ�뽻���Ƚ��鷳������������ʱ��
		for (int j = i; j < n - i - 1; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = temp;
		}

}

/* ʵ�ֶ�������д�ĺü�� */

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
