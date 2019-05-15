

#include "LeetCode.h"


/* LRU������ƣ����������ʹ�û������
 * �����hashmap��list��ֵ��ѧϰ
 * ˼·����ֵ��Ҫ��map������������Ҫ˳��������
 * ����ͷ��β��������Ԫ���ƶ��������뵽�ľ���list
 */

class LRUCache {
private:
	struct LRUnode {
		int key;
		int value;
		struct LRUnode *prev, *next;
		LRUnode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
	};
	int count;
	int cap;
	LRUnode *first;
	LRUnode *last;
	unordered_map<int, LRUnode *> m;

	void insert_into_end(LRUnode *node) {
		node->next = last;
		if (last->prev) {
			node->prev = last->prev;
			last->prev->next = node;
		}
		last->prev = node;
	}

	void move_into_end(LRUnode *node) {
		if (!node || node == last || node->next == last) return;
		auto prev = node->prev;
		auto next = node->next;
		if (prev) {
			prev->next = next;
			next->prev = prev;
		} else {
			first = next;
			first->prev = nullptr;
		}
		insert_into_end(node);
	}


public:
	LRUCache(int capacity) : count(0), cap(capacity), first(nullptr), last(new LRUnode(-1, -1)) {}

	~LRUCache() {
		for (auto it : m)
			delete it.second;
		delete last;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it != m.end()) {
			move_into_end(it->second);
			return it->second->value;
		}
		return -1;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if (it != m.end()) {
			// δ��������
			move_into_end(it->second);
			it->second->value = value;
		} else {
			// ��������
			auto new_node = new LRUnode(key, value);
			if (first == nullptr)
				first = new_node;
			m.insert({ key, new_node });
			++count;
			insert_into_end(new_node);
			if (cap < count) {
				auto tmp = first;
				first = first->next;
				first->prev = nullptr;
				m.erase(tmp->key);
				delete tmp;
				--count;
			}
		}
	}
};
