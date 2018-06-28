#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::partition(ListNode* head, int x) {
    if (nullptr == head) return head;
    ListNode* iter = head;
    ListNode* SmallHead = nullptr;
    ListNode* SmallIter = nullptr;
    ListNode* BigHead = nullptr;
    ListNode* BigIter = nullptr;
    while (iter) {
	if (iter->val >= x) {
	    if (BigHead) {
		BigIter->next = iter;
		BigIter = BigIter->next;
	    } else
		BigHead = BigIter = iter;
	} else {
	    if (SmallHead) {
		SmallIter->next = iter;
		SmallIter = SmallIter->next;
	    } else
		SmallHead = SmallIter = iter;
	}
	iter = iter->next;
    }
    if (BigIter)
	BigIter->next = nullptr;
    if (SmallHead) {
	SmallIter->next = BigHead;
	return SmallHead;
    } else {
	return BigHead;
    }
}
