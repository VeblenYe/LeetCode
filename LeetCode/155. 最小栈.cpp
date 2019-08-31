

#include "LeetCode.h"


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		sData.push(x);
		if (sMin.empty() || x <= sMin.top())
			sMin.push(x);
	}

	void pop() {
		if (sData.top() == sMin.top()) {
			sMin.pop();
		}
		sData.pop();
	}

	int top() {
		return sData.top();
	}

	int getMin() {
		return sMin.top();
	}
private:
	stack<int> sData;
	stack<int> sMin;
};
