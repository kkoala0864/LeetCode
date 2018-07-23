#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<ListNode*> input;
    vector<vector<int>> vals = {{{1,4,5},{1,3,4},{2,6}}};
    for (const auto& val : vals) {
	ListNode* localHead = nullptr;
	ListNode* iter = nullptr;
	for (const auto& v : val) {
	    if (localHead == nullptr) {
		localHead = new ListNode(v);
		iter = localHead;
	    } else {
		iter->next = new ListNode(v);
		iter = iter->next;
	    }
	}
	input.emplace_back(localHead);
    }
    Solution* test = new Solution();
    ListNode* ret = test->mergeKLists(input);
    ListNode* iter = ret;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;
    return 0;
}

