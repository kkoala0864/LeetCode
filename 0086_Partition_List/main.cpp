#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1,4,3,2,5,2};
    ListNode* head = nullptr;
    ListNode* iter = nullptr;
    for (int i = 0 ; i < input.size() ; ++i) {
	if (!head) {
	    head = new ListNode(input.at(i));
	    iter = head;
	} else {
	    iter->next = new ListNode(input.at(i));
	    iter = iter->next;
	}
    }
    Solution* test = new Solution();
    ListNode* ret = test->partition(head, 3);
    iter = ret;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    return 0;
}

