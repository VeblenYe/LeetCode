
#include "LeetCode.h"


class Node {
public:
	int val;
	Node* prev = nullptr;
	Node* next = nullptr;
	Node* child = nullptr;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};


inline void aux(Node *x, Node *y) {
	x->next = y;
	x->child = nullptr;
	y->prev = x;
}


Node* flatten(Node* head) {

	if (head == nullptr || (head->next == nullptr && head->child == nullptr))
		return head;

	stack<Node *> nstack;
	Node *cur = head;

	while (cur) {
		// 如果当前节点没有孩子节点
		if (!cur->child) {
			// 同时没有后继节点
			if (!cur->next) {
				// 且栈非空
				if (!nstack.empty()) {
					aux(cur, nstack.top());
					nstack.pop();
					cur = cur->next;
				}
				else
					return head;
			}
			// 存在后继节点
			else
				cur = cur->next;
		}
		// 如果当前节点有孩子节点
		else {
			if (cur->next)
				nstack.push(cur->next);
			aux(cur, cur->child);
			cur = cur->next;
		}
	}
}
