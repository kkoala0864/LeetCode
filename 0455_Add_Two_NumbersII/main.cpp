#include <Solution.h>
#include <iostream>
using namespace std;

int main(void) {
    ListNode* l1 = new ListNode(5);
    ListNode* l2 = new ListNode(5);
    Solution* test = new Solution();
    ListNode *ret = test->addTwoNumbers(l1, l2);
    cout << ret->val << endl;

    return 0;
}

