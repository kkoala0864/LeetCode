#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    ListNode* head = new ListNode(10);
    ListNode* iter = head;
    for (int i = 0 ; i < 3 ; ++i) {
	ListNode* next = new ListNode(10 + i + 1);
	iter->next = next;
	iter = iter->next;
    }

    test->reorderList(head);
    iter = head;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;
    return 0;
}

