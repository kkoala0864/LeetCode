#include <Solution.h>
#include <iostream>

using namespace std;


ListNode* Solution::reverseList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* prev = nullptr;
    ListNode* iter = nullptr;
    ListNode* iterNext = head;

    while (iterNext) {
	prev = iter;
	iter = iterNext;
	iterNext = iterNext->next;
	iter->next = prev;
    }
    return iter;
}
