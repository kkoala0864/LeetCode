#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {
    shared_ptr<ListNode> first = make_shared<ListNode>(13);
    shared_ptr<ListNode> second = make_shared<ListNode>(12);
    shared_ptr<ListNode> third = make_shared<ListNode>(11);
    shared_ptr<ListNode> fourth = make_shared<ListNode>(11);
    shared_ptr<ListNode> five = make_shared<ListNode>(12);
    shared_ptr<ListNode> six = make_shared<ListNode>(56);
    shared_ptr<ListNode> seven = make_shared<ListNode>(43);
    shared_ptr<ListNode> eight = make_shared<ListNode>(43);
    shared_ptr<ListNode> nine = make_shared<ListNode>(21);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;

    shared_ptr<ListNode> iter = first;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    Solution* test = new Solution();
    test->removeDuplicatesAll(first);

    iter = first;
    while (iter) {
	cout << iter->val << " ";
	iter = iter->next;
    }
    cout << endl;

    return 0;
}

