#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *four = new ListNode(4);
    ListNode *five = new ListNode(5);
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = five;

    Solution* test = new Solution();

    ListNode * ret = test->oddEvenList(first);
    while (ret != nullptr) {
	cout << ret->val << " ";
	ret = ret->next;
    }
    cout << endl;
    return 0;
}

