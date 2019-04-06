
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//���˼·���� ListA + ListB = A + intersection + B + intersection
//            ListB + ListA = B + intersection + A + intersection
//�ô�A��ʾListA����ǹ��� B��ʾlistB����ǹ��еģ�
//���Կ����ڵڶ���intersection�Ŀ�ͷ������������һ���ģ���Ȼ���
//�������ǿ��Ա���A�ٱ���B����һ������B�ٱ���A������ָ��ض��ڵڶ���������������û�н������ǿ�ָ��
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
