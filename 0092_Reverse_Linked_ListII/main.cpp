#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    vector<int> input = {3, 5};
    ListNode* head = nullptr;
    ListNode* iter = nullptr;
    for (int i = 0 ; i < input.size() ; ++i) {
	if (head == nullptr) {
	    head = new ListNode(input.at(i));
	    iter = head;
	} else {
	    iter->next = new ListNode(input.at(i));
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
    ListNode* ret = test->reverseBetween(head, 1, 2);
    while (ret) {
	cout << ret->val << " ";
	ret = ret->next;
    }
    cout << endl;
    return 0;
}

