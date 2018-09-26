#pragma once



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


Node* flatten(Node* head) {

}
