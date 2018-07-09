#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr) return nullptr;
    ListNode* prevHead = nullptr;
    ListNode* afterTail = nullptr;
    ListNode* revertHead = nullptr;

    int Cnt(0);
    ListNode* prev = nullptr;
    ListNode* iter = nullptr;
    ListNode* iterNext = head;

    while (iterNext) {
	prev = iter;
	iter = iterNext;
	iterNext = iterNext->next;
	++Cnt;
	if (m == Cnt) {
	    prevHead = prev;
	    revertHead = iter;
	}
	if (Cnt >= m && Cnt <= n) iter->next = prev;
	if (n == Cnt) {
	   afterTail = iterNext;
	   break;
	}
    }
    if (prevHead)
	prevHead->next = iter;
    else head = iter;

    revertHead->next = iterNext;
    return head;
}
