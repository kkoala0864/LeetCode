#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(3);
    ListNode* five = new ListNode(4);
    ListNode* six = new ListNode(4);
    ListNode* seven = new ListNode(5);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = five;
    five->next = six;
    six->next = seven;

    ListNode* iter = first;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    Solution* test = new Solution();
    ListNode* ret = test->deleteDuplicates(first);

    if (ret) {
	cout << "valid" << endl;
    } else {
	cout << "not valid" << endl;
    }
    iter = ret;
    while (iter) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    cout << endl;

    return 0;
}

