
#include "ListNode.h"


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//这个思路就是 ListA + ListB = A + intersection + B + intersection
//            ListB + ListA = B + intersection + A + intersection
//用大A表示ListA里面非共有 B表示listB里面非共有的，
//可以看到在第二个intersection的开头两个链表长度是一样的，必然相等
//所以我们可以遍历A再遍历B，另一个遍历B再遍历A，两个指针必定在第二个交集处相遇，没有交集就是空指针
	if (!headA && !headB)
		return nullptr;
	ListNode *cursorA = headA;
	ListNode *cursorB = headB;
	while (cursorA != cursorB) {
		if (!cursorA)
			cursorA = headB;
		else
			cursorA = cursorA->next;
		if (!cursorB)
			cursorB = headA;
		else
			cursorB = cursorB->next;
	}
	return cursorA;
}
