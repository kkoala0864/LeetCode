#include <Solution.h>
#include <iostream>

using namespace std;

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* AIter = headA;
    ListNode* BIter = headB;
    int ACnt(0);
    int BCnt(0);
    while (AIter) {
	++ACnt;
	AIter = AIter->next;
    }
    while (BIter) {
	++BCnt;
	BIter = BIter->next;
    }
    AIter = headA;
    BIter = headB;
    if (ACnt > BCnt) {
	int diff = ACnt - BCnt;
	while (diff-- > 0) {
	    AIter = AIter->next;
	}
    } else if (BCnt > ACnt) {
	int diff = BCnt - ACnt;
	while (diff-- > 0) {
	    BIter = BIter->next;
	}
    }
    while (AIter != BIter) {
	AIter = AIter->next;
	BIter = BIter->next;
    }
    return AIter;
}
