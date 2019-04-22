
#include "LeetCode.h"

/*
ListNode *merge(ListNode *l, ListNode *r) {
	ListNode *dummyHead = new ListNode(0);
	ListNode *cur = dummyHead;

	while (l && r) {
		if (l->val <= r->val) {
			cur->next = l;
			l = l->next;
		}
		else {
			cur->next = r;
			r = r->next;
		}
		cur = cur->next;
	}

	if (l)
		cur->next = l;
	else if (r)
		cur->next = r;

	return dummyHead->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
	if (lists.empty())
		return nullptr;
	if (lists.size() == 1)
		return lists[0];

	ListNode *ans1 = lists[0];
	ListNode *ans2 = lists[1];
	ListNode *ans3;
	ListNode *ans = merge(ans1, ans2);
	int i;
	for (i = 2; i < lists.size() - 3; i += 4) {
		ans1 = merge(lists[i], lists[i + 1]);
		ans2 = merge(lists[i + 2], lists[i + 3]);
		ans3 = merge(ans1, ans2);
		ans = merge(ans, ans3);
	}
	for (; i < lists.size(); ++i)
		ans = merge(ans, lists[i]);
	return ans;
}
*/