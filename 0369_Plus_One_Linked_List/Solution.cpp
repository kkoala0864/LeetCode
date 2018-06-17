#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

ListNode* Solution::plusOne(ListNode* head) {
    stack<ListNode*> st;
    ListNode* iter = head;
    while (iter) {
	st.push(iter);
	iter = iter->next;
    }

    int carryin(1);
    while (carryin == 1 && !st.empty()) {
	ListNode* cur_bit = st.top(); st.pop();
	cur_bit->val = (cur_bit->val + 1) % 10;
	if (cur_bit->val == 0) {
	    carryin = 1;
	} else {
	    carryin = 0;
	}
    }
    if (carryin == 1 && st.empty()) {
	ListNode* carryNew = new ListNode(1);
	carryNew->next = head;
	head = carryNew;
    }
    return head;
}
