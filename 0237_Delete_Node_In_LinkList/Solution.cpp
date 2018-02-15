#include <Solution.h>


void Solution::deleteNode(ListNode* node) {
	if (!node)
		return;

	ListNode *pNext = node->next;
	node->val = pNext->val;
	node->next = pNext->next;
	delete pNext;
	pNext = NULL;
}
