#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;

//ListNode* Solution::deleteDuplicates(ListNode* head) {
//    vector<ListNode *> history;
//    ListNode* iter = head;
//
//    while (iter && iter->next) {
//	if (iter->val == iter->next->val) {
//	    ListNode* distinct = iter;
//	    while (distinct) {
//		cout << distinct->val << endl;
//		ListNode* del = distinct;
//		if (distinct->next) {
//		    if (distinct->val == distinct->next->val) {
//			distinct = distinct->next;
//			delete(del);
//		    } else {
//			distinct = distinct->next;
//			delete(del);
//			break;
//		    }
//		} else {
//		    distinct = nullptr;
//		}
//	    }
//
//	    if (history.empty()) {
//		head = iter = distinct;
//	    } else {
//		iter = distinct;
//		history.back()->next = distinct;
//	    }
//	} else {
//	    history.push_back(iter);
//	    iter = iter->next;
//	}
//    }
//    return head;
//}


ListNode* Solution::deleteDuplicates(ListNode* head) {
    if (nullptr == head) {
	return nullptr;
    }

    ListNode dummy(INT_MAX);
    dummy.next = head;
    ListNode *pre = &dummy, *cur = head, *next = head->next;

    while (cur) {
	bool duplicate = false;
	next = cur->next;
	while (next != nullptr && cur->val == next->val) {
	    duplicate = true;
	    cur->next = next->next;
	    delete(next);
	    next = cur->next;
	}

	if (duplicate) {
	    pre->next = next;
	    delete(cur);
	    cur = next;
	} else {
	    pre = cur;
	    cur = next;
	}
    }

    return dummy.next;
}

