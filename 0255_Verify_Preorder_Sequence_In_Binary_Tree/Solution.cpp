#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;

bool verify(vector<int>& preorder, int start, int end) {
    if (end <= start) return true;
    int firstBig(INT_MAX);
    for (int i = start ; i <= end ; ++i) {
	if (preorder.at(i) > preorder.at(start)) {
	    firstBig = firstBig > i ? i : firstBig;
	}
	if (firstBig != INT_MAX && preorder.at(i) < preorder.at(start)) {
	    return false;
	}
    }
    if (firstBig == INT_MAX) {
	return verify(preorder, start+1, end);
    }
    return verify(preorder, start+1, firstBig-1) && verify(preorder, firstBig, end);
}

bool Solution::verifyPreorder2(vector<int>& preorder) {
    return verify(preorder, 0, preorder.size()-1);
}

bool Solution::verifyPreorder(vector<int>& preorder) {
    if (preorder.empty()) {
	return true;
    }
    stack<int> st;
    st.push(preorder.at(0));
    int root(INT_MIN);
    for (int i = 1 ; i < preorder.size() ; ++i) {
	if (preorder.at(i) < root) {
	    return false;
	}
	while (!st.empty() && st.top() < preorder.at(i)) {
	    root = st.top();
	    st.pop();
	}
	st.push(preorder.at(i));
    }
    return true;
}

