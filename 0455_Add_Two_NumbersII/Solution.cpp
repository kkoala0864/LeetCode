#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<ListNode *> stackL1;
    stack<ListNode *> stackL2;

    ListNode *iterL1 = l1;
    ListNode *iterL2 = l2;
    while (iterL1) {
	stackL1.emplace(iterL1);
	iterL1 = iterL1->next;
    }
    while (iterL2) {
	stackL2.emplace(iterL2);
	iterL2 = iterL2->next;
    }

    int carryin(0);
    stack<ListNode*> *wb = stackL1.size() > stackL2.size() ? &stackL1 : &stackL2;
    ListNode* retHead = stackL1.size() > stackL2.size() ? l1 : l2;
    while (!stackL1.empty() && !stackL2.empty()) {
	int val = stackL1.top()->val + stackL2.top()->val + carryin;
	wb->top()->val = val % 10;
	carryin = val / 10;
	stackL1.pop(); stackL2.pop();
    }

    while (carryin > 0 && !wb->empty()) {
	int val = wb->top()->val + carryin;
	wb->top()->val = val % 10;
	carryin = val / 10;
	wb->pop();
    }

    if (carryin > 0) {
	ListNode* extraNode = new ListNode(1);
	extraNode->next = retHead;
	retHead = extraNode;
    }

    return retHead;
}


