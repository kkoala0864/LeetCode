#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    if (l1 == nullptr || l2 == nullptr) return l1 == nullptr ? l2 : l1;

    ListNode* l1Iter = l1;
    ListNode* l2Iter = l2;
    ListNode* copyHead = nullptr;
    ListNode* copyIter = nullptr;
    ListNode* beAppend = nullptr;
    while (l1Iter && l2Iter) {
	beAppend = l1Iter->val < l2Iter->val ? l1Iter : l2Iter;
	if (copyIter) {
	    copyIter->next = beAppend;
	    copyIter = copyIter->next;
	} else {
	    copyHead = beAppend;
	    copyIter = copyHead;
	}
	if (beAppend == l1Iter) l1Iter = l1Iter->next;
	else l2Iter = l2Iter->next;
    }
    if (l1Iter) {
	copyIter->next = l1Iter;
    } else {
	copyIter->next = l2Iter;
    }
    return copyHead;
}
