#include <Solution.h>
#include <iostream>
#include <stack>
using namespace std;

NestedIterator::NestedIterator(vector<NestedInteger> &nestedList) {
    stack<NestedInteger> stk;
    for (const auto& idx : nestedList) {
	stk.push(idx);
    }
    while (!stk.empty()) {
	if (stk.top().isInteger()) {
	    retStk.push(stk.top().getInteger());
	    stk.pop();
	} else {
	    vector<NestedInteger> list = stk.top().getList();
	    stk.pop();
	    for (const auto& idx : list) {
		stk.push(idx);
	    }
	}
    }
}

int NestedIterator::next() {
    int val = retSTK.top();
    retSTK.pop();
    return val;
}

bool NestedIterator::hasNext() {
    return !retSTK.empty();
}
