#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) return head;
    int Size(0);
    ListNode* iter = head;
    while (iter) {
	iter = iter->next;
	++Size;
    }

    if (k >= Size) k = k % Size;
    if (k == 0) return head;

    iter = head;
    ListNode* prev = nullptr;
    int shiftSize = Size - k;
    while (shiftSize-- > 0) {
	prev = iter;
	iter = iter->next;
    }

    ListNode* newHead = iter;
    while (iter->next) {
	iter = iter->next;
    }
    iter->next = head;
    prev->next = nullptr;
    return newHead;
}
