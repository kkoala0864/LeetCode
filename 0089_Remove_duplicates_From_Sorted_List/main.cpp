#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(2);
    ListNode* fourth = new ListNode(2);
    ListNode* five = new ListNode(3);
    ListNode* six = new ListNode(3);
    ListNode* seven = new ListNode(21);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = five;
    five->next = six;
    //six->next = seven;

    ListNode* iter = first;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    Solution* test = new Solution();
    test->deleteDuplicates(first);

    iter = first;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    return 0;
}

