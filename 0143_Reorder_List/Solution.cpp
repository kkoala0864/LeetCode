#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

void Solution::reorderList(ListNode* head) {
    if (nullptr == head) return;
    stack<ListNode*> st;

    ListNode* iter = head;
    while (iter) {
	st.emplace(iter);
	iter = iter->next;
    }
    iter = head;
    while (iter && iter != st.top() && iter->next != st.top()) {
	st.top()->next = iter->next;
	iter->next = st.top();
	st.pop();
	iter = iter->next->next;
    }
    iter == st.top() ? iter->next = nullptr : iter->next->next = nullptr;
}
