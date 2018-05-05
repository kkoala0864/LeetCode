#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
	ListNode *one = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *three = new ListNode(3);
	ListNode *four = new ListNode(4);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = four;

	Solution* test = new Solution();
	ListNode *ret = test->detectCycle(one);
	ListNode *ret2 = test->detectCycleWithoutExtraSpace(one);
	if (ret2) {
		cout << ret2->val << endl;
	} else {
		cout << "empty" << endl;
	}

}

