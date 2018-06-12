#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

using namespace std;
int main(void) {
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *four = new ListNode(4);
    Solution* test = new Solution();

    first->next = second;
    second->next = third;
    ListNode *ret = test->swapPairs(first);
    while (ret){
	cout << ret->val << " ";
	ret = ret->next;
    }
    cout << endl;
    return 0;
}

