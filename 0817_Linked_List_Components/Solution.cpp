#include <Solution.h>
#include <iostream>
#include <unordered_set>

using namespace std;

int Solution::numComponents(ListNode* head, vector<int>& G) {
    unordered_set<int> hashTable;
    int cnt(0);

    for (const auto& idx : G) {
	hashTable.emplace(idx);
    }

    while (head) {
	if (hashTable.find(head->val) != hashTable.end()) {
	    ++cnt;
	    while (head && hashTable.find(head->val) != hashTable.end()) {
		head = head->next;
	    }
	} else {
	    head = head->next;
	}
    }
    return cnt;
}
