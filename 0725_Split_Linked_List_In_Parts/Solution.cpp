#include <Solution.h>
#include <iostream>

using namespace std;

vector<ListNode*> Solution::splitListToParts(ListNode* root, int k) {
    vector<ListNode*> ret(k, root);
    if (nullptr == root || 1 == k) return ret;
    ListNode* last = root;
    while (last) {
	int lastCnt(0);
	while (last && (lastCnt < k)) {
	    last = last->next;
	    ++lastCnt;
	}
	for (int i = k-1 ; i >= 1  ; --i) {
	    int step = lastCnt > i ? i : lastCnt;
	    ListNode* pre = nullptr;
	    for (int j = 0 ; j < step && ret.at(i); ++j) {
		pre = ret.at(i);
		ret.at(i) = ret.at(i)->next;
	    }
	    if (!last && pre) {
		pre->next = nullptr;
	    }
	}
    }
    return ret;
}
