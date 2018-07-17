#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    vector<int> input = {1,2,3,4,5};
    ListNode* head = nullptr;
    ListNode* iter = nullptr;
    for (const auto& val : input) {
	if (nullptr == iter) {
	    head = new ListNode(val);
	    iter = head;
	} else {
	    iter->next = new ListNode(val);
	    iter = iter->next;
	}
    }
    Solution* test = new Solution();
    ListNode* ret = test->reverseKGroup(head, 3);
    while (ret) {
	cout << ret->val << " ";
	ret = ret->next;
    }
    cout << endl;


    return 0;
}

