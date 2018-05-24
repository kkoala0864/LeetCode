#include <Solution.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

ListNode* Solution::removeDuplicatesKeepFirst(ListNode* head) {
    if (nullptr == head) {
	return head;
    }

    ListNode* iter = head;
    while (iter && iter->next) {
	if (iter->val == iter->next->val) {
	    ListNode* eliminate = iter->next;
	    iter->next = iter->next->next;
	    delete(eliminate);
	} else {
	    iter = iter->next;
	}
    }
    return head;
}


ListNode* Solution::removeDuplicatesAll(ListNode* head) {
   if (nullptr == head) {
	return head;
   }

   ListNode* iter = head;
   vector<ListNode *> history;

   while (iter && iter->next) {
       if (iter->val == iter->next->val) {
	   ListNode* firstDifferent = iter;
	   ListNode* eliminate = firstDifferent;
	   while (firstDifferent) {
	       if (firstDifferent->next) {
		   if (firstDifferent->val == firstDifferent->next->val) {
		       firstDifferent = firstDifferent->next;
		       delete(eliminate);
		       eliminate = firstDifferent;
		   } else {
		       firstDifferent = firstDifferent->next;
		       delete(eliminate);
		       eliminate = firstDifferent;
		       break;
		   }
	       } else {
		    firstDifferent = nullptr;
	       }
	   }

	   if (history.empty()) {
	       head = iter = firstDifferent;
	   } else {
	       iter = history.back();
	       history.pop_back();
	       iter->next = firstDifferent;
	   }
       } else {
	   history.push_back(iter);
	   iter = iter->next;
       }
   }
   return head;
}
