#include <Solution.h>
#include <unordered_map>
#include <iostream>

using std::unordered_map;
using std::cout;
using std::endl;

ListNode * Solution::detectCycleWithoutExtraSpace(ListNode *head) {
	if (nullptr == head || nullptr == head->next) {
		return nullptr;
	}

	ListNode *first = head;
	ListNode *second = head;
	bool isCycle = false;

	while (nullptr != second->next && nullptr != second->next->next) {
		first = first->next;
		second = second->next->next;
		if (first == second) {
			isCycle = true;
			break;
		}
	}

	if (!isCycle) {
		return nullptr;
	}
	first = head;
	while (first != second) {
		first = first->next;
		second = second->next;
	}
	return first;
}



ListNode * Solution::detectCycle(ListNode *head) {
	if (nullptr == head) {
		return nullptr;
	}

	if (head->next == head) {
		return head;
	}

	unordered_map<int,bool> flag;
	flag[reinterpret_cast<intptr_t>(head)] = true;
	ListNode *iter = head->next;

	while (iter) {
		flag[reinterpret_cast<intptr_t>(iter)] = true;
		if(iter->next) {
			if (flag[reinterpret_cast<intptr_t>(iter->next)]) {
				return iter->next;
			}
		}
		iter = iter->next;
	}

	return nullptr;
}
