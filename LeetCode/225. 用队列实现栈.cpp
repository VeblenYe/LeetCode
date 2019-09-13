

#include "LeetCode.h"


// 用双栈实现比较麻烦


class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		//nothing to do
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
		//将前面的size-1个元素放到后面去
		for (int i = 0; i < q.size() - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		auto res = top();
		q.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
private :
	queue<int> q;
};
