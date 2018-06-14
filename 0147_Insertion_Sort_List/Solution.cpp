#include <Solution.h>

ListNode* Solution::insertionSortList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* Sorted = head;
    head = head->next;
    Sorted->next = nullptr;

    while (head != nullptr) {
	ListNode* iter = head;
	head = head->next;

	if (Sorted->val > iter->val) {
	    iter->next = Sorted;
	    Sorted = iter;
	} else {
	    ListNode* Compare = Sorted;
	    while (Compare->next && Compare->next->val < iter->val) {
		Compare = Compare->next;
	    }
	    iter->next = Compare->next;
	    Compare->next = iter;
	}
    }
    return Sorted;
}
