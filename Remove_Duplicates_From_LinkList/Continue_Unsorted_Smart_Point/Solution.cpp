#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;

void Solution::removeDuplicatesKeepFirst(shared_ptr<ListNode> head) {
    if (nullptr == head) {
	return;
    }

    shared_ptr<ListNode> iter = head;
    while (iter && iter->next) {
        if (iter->val == iter->next->val) {
            iter->next = iter->next->next;
        } else {
	    iter = iter->next;
	}
    }
}

void Solution::removeDuplicatesAll(shared_ptr<ListNode> head) {
   if (nullptr == head) {
	return;
   }

   shared_ptr<ListNode> iter = head;
   vector<shared_ptr<ListNode>> history;

   while (iter && iter->next) {
       if (iter->val == iter->next->val) {
	   shared_ptr<ListNode> firstDifferent = iter;

	   while (firstDifferent) {
	       if (firstDifferent->next) {
		   if (firstDifferent->val == firstDifferent->next->val) {
		       firstDifferent = firstDifferent->next;
		   } else {
		       firstDifferent = firstDifferent->next;
		       break;
		   }
	       } else {
		    firstDifferent.reset();
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
}
