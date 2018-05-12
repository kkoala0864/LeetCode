#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool Solution::hasCycle(ListNode* head) {
	if (nullptr == head || nullptr == head->next || nullptr == head->next->next) {
		return false;
	}

	if (head->next == head) {
		return true;
	}

	ListNode* oneStep = head->next;
	ListNode* twoStep = head->next->next;

	while (oneStep != twoStep && twoStep->next && twoStep->next->next) {
		oneStep = oneStep->next;
		twoStep = twoStep->next->next;
	}

	if (twoStep) {
		return true;
	} else {
		return false;
	}
}
