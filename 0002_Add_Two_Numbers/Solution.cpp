#include <iostream>
#include <Solution.h>

using namespace std;

Solution::Solution() {};

Solution::~Solution() {};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {

	if ( !l1 && !l2 ) {
		return NULL;
	} else if ( !l1 ) {
		return l2;
	} else if ( !l2 ) {
		return l1;
	}

	ListNode* Head = NULL;
	ListNode* Tail = NULL;
	int carry = 0;
	while ( l1 && l2 ) {
		int sum = l1->val + l2->val + carry;
		l1 = l1->next;
		l2 = l2->next;

		if ( !Head ) {
			Tail = new ListNode(0);
			Head = Tail;
		} else {
			Tail->next = new ListNode(0);
			Tail = Tail->next;
		}
		Tail->next = NULL;
		Tail->val = sum % 10;
		carry = sum / 10;
	}

	if ( l1 ) {
		Tail->next = l1;
	} else {
		Tail->next = l2;
	}

	if ( 0 == carry ) {
		return Head;
	}

	while ( carry ) {
		if ( Tail->next ) {
			Tail = Tail->next;
			Tail->val += carry;
			carry = Tail->val / 10;
			Tail->val %= 10;
		} else {
			Tail->next = new ListNode(0);
			Tail = Tail->next;
			Tail->val = 1;
			Tail->next = NULL;
			return Head;
		}
	}

	return Head;

}
