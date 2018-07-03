#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    vector<int> input = {1,2,3};
    ListNode* head = nullptr;
    ListNode* iter = head;
    for (const auto& idx : input) {
	if (!head) {
	    head = new ListNode(idx);
	    iter = head;
	} else {
	    iter->next = new ListNode(idx);
	    iter = iter->next;
	}
    }
    iter = head;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;
    Solution* test = new Solution();
    ListNode* ret = test->removeNthFromEnd2(head, 3);
    iter = ret;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    return 0;
}

