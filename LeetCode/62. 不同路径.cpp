

#include "LeetCode.h"


// ����һ�����͵Ķ�̬�滮���⣬�䶯̬����Ϊdp[i][j] = dp[i-1][j] + dp[i][j-1]
// �ɴ˿�֪���ǽ���Ҫ�������Ϳ��������һ����������Ҫ���������飬���пռ������Ż�


int uniquePaths(int m, int n) {
	vector<int> ivec(n, 1);
	for (int i = 1; i < m; ++i)	// ������Ҫ���Ȱ�ÿһ�е�ֵ����������Ծ������𲽸���
		for (int j = 1; j < n; ++j)
			ivec[j] += ivec[j - 1];
	return ivec.back();
}

