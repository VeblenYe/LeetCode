


#include "LeetCode.h"
#include "BinarySearchTree.h"


int kthSmallest(TreeNode *root, int k) {
	auto pNode = root;
	stack<TreeNode *> st;
	while (pNode || !st.empty()) {
		while (pNode) {
			st.push(pNode);
			pNode = pNode->left;
		}
		if (!st.empty()) {
			pNode = st.top();
			st.pop();
			if ((--k) == 0) return pNode->val;
			pNode = pNode->right;
		}
	}

	return -1;
}
