#include <Solution.h>
#include <iostream>

using namespace std;

ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* iter = head;
    while (iter && iter->next) {
	if (iter->val == iter->next->val) {
	    ListNode* del = iter->next;
	    iter->next = iter->next->next;
	    delete(del);
	} else {
	    iter = iter->next;
	}
    }
    return head;
}
