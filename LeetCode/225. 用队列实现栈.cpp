

#include "LeetCode.h"


// ��˫ջʵ�ֱȽ��鷳


class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		//nothing to do
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
		//��ǰ���size-1��Ԫ�طŵ�����ȥ
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
