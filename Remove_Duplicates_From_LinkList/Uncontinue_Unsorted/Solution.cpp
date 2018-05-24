#include <Solution.h>
#include <iostream>
#include <unordered_map>

using namespace std;

ListNode* Solution::removeDuplicates(ListNode* head) {
    if (nullptr == head) {
	return head;
    }
    unordered_map<int, bool> history;
    ListNode* iter = head;
    history[iter->val] = 1;
    while (iter->next) {
	if (history[iter->next->val]) {
	    ListNode* tmp = iter->next;
	    iter->next = iter->next->next;
	    tmp->next = nullptr;
	    delete(tmp);
	} else {
	    history[iter->next->val] = true;
	    iter = iter->next;
	}
    }
    return head;
}

