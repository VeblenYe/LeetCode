

#include "LeetCode.h"


vector<int> sortArrayByParity(vector<int> &A) {
	if (A.empty())
		return {};

	int i = 0, j = A.size() - 1;
	while (i < j) {
		while (i < j && A[i] & 0x1 == 0) ++i;
		while (i < j && A[j] & 0x1 != 0) --j;
		swap(A[i], A[j]);
	}

	return A;
}
