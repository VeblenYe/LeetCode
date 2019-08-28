

#include "LeetCode.h"


// 思路：使用双指针，慢指针指向链表中当前不重复的元素，快指针负责跳过所有重复元素
// 而后链接快慢指针并更新


ListNode *deleteDuplicates(ListNode *head) {
	if (!head || !head->next)
		return head;

	auto dummy = new ListNode(0);
	dummy->next = head;
	auto pre = dummy; // 慢指针
	while (pre->next) {
		auto cur = pre->next;	// 快指针
		while (cur->next && cur->val == cur->next->val) {	// 跳过所有重复元素，并删除
			auto tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		if (cur != pre->next) {	// 如果cur确实跳过重复元素，则cur是最后一个重复元素，更新慢指针后继并删除cur
			pre->next = cur->next;
			delete cur;
		}
		else
			pre = pre->next;	// cur不是重复元素，移动慢指针
	}
	return dummy->next;
}
