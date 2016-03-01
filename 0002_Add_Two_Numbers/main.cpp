#include <Solution.h>
#include <iostream>
int main() {

	ListNode* l11 = new ListNode(3);
	ListNode* l12 = new ListNode(7);
	l11->next = l12;
	ListNode* l21 = new ListNode(9);
	ListNode* l22 = new ListNode(2);
	l21->next = l22;
	Solution test;
	ListNode* ret = test.addTwoNumbers(l11,l21);
	while ( ret ) {
		std::cout << ret->val << std::endl;
		ret = ret->next;
	}
}
