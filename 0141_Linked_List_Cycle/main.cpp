#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {

	ListNode *node1 = new ListNode(10);
	ListNode *node2 = new ListNode(20);
	ListNode *node3 = new ListNode(30);
	node1->next = node2;
	Solution* test = new Solution();
	bool ret = test->hasCycle(node1);
	cout << ret << endl;

	return 0;
}

