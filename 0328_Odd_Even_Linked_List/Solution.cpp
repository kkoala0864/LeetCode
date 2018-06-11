#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::oddEvenList(ListNode* head) {
    if (head) {
	ListNode *pOddTail = head;
	ListNode *pEvenHead = head->next, *pEvenTail = head->next;
	if (pEvenTail == nullptr) return head;
	ListNode *iter = pEvenTail->next;

	int count(1);
	while (iter != nullptr) {
	    if (count & 1) {
		pOddTail->next = iter;
		pOddTail = iter;
	    } else {
		pEvenTail->next = iter;
		pEvenTail = iter;
	    }
	    ++count;
	    iter = iter->next;
	}
	if (pEvenTail->next != nullptr) {
	    pEvenTail->next = nullptr;
	}

	pOddTail->next = pEvenHead;
    }
    return head;
}


ListNode * Solution::oddEvenList2(ListNode* head) const {
    if (head) {
	ListNode*oddCur = head, *evenHead = head->next, *evenCur = evenHead;
	while (evenCur && evenCur->next) {
	    oddCur = oddCur->next = evenCur->next;
	    evenCur = evenCur->next = evenCur->next->next;
	}
	oddCur->next = evenHead;
    }
    return head;
}
