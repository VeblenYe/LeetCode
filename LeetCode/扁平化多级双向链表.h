#pragma once


#include <stack>


using std::stack;


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
		// �����ǰ�ڵ�û�к��ӽڵ�
		if (!cur->child) {
			// ͬʱû�к�̽ڵ�
			if (!cur->next) {
				// ��ջ�ǿ�
				if (!nstack.empty()) {
					aux(cur, nstack.top());
					nstack.pop();
					cur = cur->next;
				}
				else
					return head;
			}
			// ���ں�̽ڵ�
			else
				cur = cur->next;
		}
		// �����ǰ�ڵ��к��ӽڵ�
		else {
			if (cur->next)
				nstack.push(cur->next);
			aux(cur, cur->child);
			cur = cur->next;
		}
	}
}
