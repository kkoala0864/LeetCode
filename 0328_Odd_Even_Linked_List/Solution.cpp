#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::oddEvenList(ListNode* head) {
    if (head) {
	ListNode *oddIter = head, *evenHead = head->next, *evenIter = evenHead;
	while (evenIter && evenIter->next) {
	    oddIter->next = evenIter->next;
	    oddIter = oddIter->next;
	    evenIter->next = oddIter->next;
	    evenIter = evenIter->next;
	}
	oddIter->next = evenHead;
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
