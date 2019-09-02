

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
	stack<int> sData;	// 数据栈，保存所有数据
	stack<int> sMin;	// 最小辅助栈，顶部为当前栈中最小的元素
};
