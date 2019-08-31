

#include "LeetCode.h"


bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
	if (pushed.size() != popped.size())
		return false;

	int n = pushed.size();
	stack<int> s;
	for (int i = 0, j = 0; i < n; ++i) {
		s.push(pushed[i]);
		while (!s.empty() && j < n && s.top() == popped[j]) {
			s.pop();
			++j;
		}
	}
	
	return s.empty();
}