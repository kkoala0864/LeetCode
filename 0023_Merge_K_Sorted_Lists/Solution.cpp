#include <Solution.h>
#include <iostream>
#include <queue>

using namespace std;

void print(ListNode* input) {
    while (input) {
	cout << input->val << " ";
	input = input->next;
    }
    cout << endl;
}
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    queue<ListNode*> que;
    for (const auto& val : lists) {
	if (val)
	    que.emplace(val);
    }
    queue<ListNode*> nextLV;

    while (!que.empty()) {
	if (que.size() == 1) {
	    if (nextLV.empty()) {
		return que.front();
	    } else {
		nextLV.emplace(que.front());
		que = move(nextLV);
		continue;
	    }
	}
	ListNode* list1 = que.front(); que.pop();
	ListNode* list2 = que.front(); que.pop();
	ListNode* retHead = nullptr;
	ListNode* appendIter = retHead;

	while (list1 && list2) {
	    if (retHead) {
		if (list1->val < list2->val) {
		    appendIter->next = list1;
		    list1 = list1->next;
		} else {
		    appendIter->next = list2;
		    list2 = list2->next;
		}
		appendIter = appendIter->next;
	    } else {
		retHead = list1->val < list2->val ? list1 : list2;
		retHead == list1 ? list1 = list1->next : list2 = list2->next;
		appendIter = retHead;
	    }
	}
	appendIter->next = list1 ? list1 : list2;
	nextLV.emplace(retHead);
	if (que.empty()) {
	    que = move(nextLV);
	}
    }
    return nullptr;
}
