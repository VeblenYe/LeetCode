

#include <vector>
#include <string>
#include <iostream>


#include "合并两个有序链表.h"
#include "ListNode.h"


using std::string;
using std::cout;
using std::endl;
using std::ends;


int main() {
	ListNode a(1);
	a.next = new ListNode(2);
	a.next->next = new ListNode(7);
	ListNode b(3);
	b.next = new ListNode(4);
	auto x = mergeTwoLists(&a, &b);
	while (x) {
		cout << x->val << ends;
		x = x->next;
	}
	getchar();
	return 0;
}
