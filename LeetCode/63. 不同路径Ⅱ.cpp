

#include "LeetCode.h"


int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

	auto Row = obstacleGrid.size();
	auto Col = obstacleGrid[0].size();

	if (obstacleGrid[0][0] == 1)
		return 0;


	for (int i = 1; i < Col; ++i)
		obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
	for (int i = 1; i < Row; ++i)
		obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;

	for (int i = 1; i < Row; ++i) {
		for (int j = 1; j < Col; ++j) {
			if (obstacleGrid[i][j] == 0) {
				obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			} else {
				obstacleGrid[i][j] = 0;
			}
		}
	}

	return obstacleGrid.back().back();
}

