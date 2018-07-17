#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
    ListNode* CntIter = head;
    int Cnt = k;
    while (Cnt-- > 0) {
	if (nullptr == CntIter) return head;
	CntIter = CntIter->next;
    }
    ListNode* NextHead = reverseKGroup(CntIter, k);
    ListNode* prev = nullptr;
    ListNode* cur = nullptr;
    ListNode* nextNode = head;

    Cnt = k;
    while (Cnt-- > 0) {
	prev = cur;
	cur = nextNode;
	nextNode = nextNode->next;
	cur->next = prev;
    }
    head->next = NextHead;
    return cur;
}
