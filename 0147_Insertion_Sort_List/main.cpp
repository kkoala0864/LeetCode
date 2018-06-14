#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* four = new ListNode(4);
    third->next = first;
    first->next = four;
    four->next = second;
    Solution* test = new Solution();
    ListNode* ret = test->insertionSortList(third);
    while (ret != nullptr) {
	cout << ret->val << " ";
	ret = ret->next;
    }
    cout << endl;

    return 0;
}

