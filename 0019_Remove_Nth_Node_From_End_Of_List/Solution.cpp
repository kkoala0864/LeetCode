#include <Solution.h>
#include <iostream>
#include <stack>
using namespace std;

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    stack<ListNode*> st;
    ListNode* iter = head;
    while (iter) {
	st.emplace(iter);
	iter = iter->next;
    }
    while (n-- > 0 && !st.empty()) {
	iter = st.top();
	st.pop();
    }
    if (st.empty()) return iter->next;
    st.top()->next = iter->next;
    iter->next = nullptr;
    return head;
}

ListNode* Solution::removeNthFromEnd2(ListNode* head, int n) {
    ListNode *prev = nullptr, *first = head, *second = head;
    while (n-- > 0) {
	second = second->next;
    }
    while (second != nullptr) {
	prev = first;
	first = first->next;
	second = second->next;
    }
    if (prev == nullptr) return prev = first->next;
    prev->next = first->next;
    first->next = nullptr;
    return head;
}
