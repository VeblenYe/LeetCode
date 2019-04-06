

struct LinkNode {
	int val;
	LinkNode *prev;
	LinkNode *next;
	LinkNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};


class MyLinkedList {
private:
	LinkNode *node;
public:
	LinkNode *begin() { return node->next; }
	LinkNode *end() { return node; }

	void insert(LinkNode *position, int val) {
		auto tmp = new LinkNode(val);
		tmp->next = position;
		tmp->prev = position->prev;
		position->prev->next = tmp;
		position->prev = tmp;
	}
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		node = new LinkNode(-1);
		node->next = node;
		node->prev = node;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		auto cur = begin();
		while (index--) {
            cur = cur->next;
			if (cur == end())
				return -1;
		}
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		insert(begin(), val);
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		insert(end(), val);
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (begin() == end())
			if (index != 0)
				return;
			else {
				insert(begin(), val);
				return;
			}
		auto cur = begin();
		while (index--) {
			cur = cur->next;
			if (cur == end() && index != 0)
				return;
		}
		insert(cur, val);
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		auto cur = begin();
		while (index--) {
            cur = cur->next;
			if (cur == end())
				return;
		}
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */