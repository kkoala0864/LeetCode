#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {
    ListNode* first = new ListNode(13);
    ListNode* second = new ListNode(11);
    ListNode* third = new ListNode(11);
    ListNode* fourth = new ListNode(11);
    ListNode* five = new ListNode(12);
    ListNode* six = new ListNode(56);
    ListNode* seven = new ListNode(43);
    ListNode* eight = new ListNode(43);
    ListNode* nine = new ListNode(21);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;

    ListNode* iter = first;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    Solution* test = new Solution();
    ListNode* ret = test->removeDuplicatesAll(first);

    iter = ret;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    return 0;
}

