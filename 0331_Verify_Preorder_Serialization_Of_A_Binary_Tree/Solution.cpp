#include <Solution.h>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

bool Solution::isValidSerialization(string preorder) {
    if (preorder.empty())
	return true;
    if (preorder.size() == 1 && preorder.at(0) == '#')
	return true;
    stack<pair<string, bool>> st;
    int start(0);
    int end = start;
    while (end < preorder.size() && preorder.at(end) != ',') {
	++end;
    }
    string root = preorder.substr(start, end - start + 1);
    start = end+1;
    if (root != "#" || root != "#,")
	return false;
    else
	st.emplace(root, false);
    while (start < preorder.size()) {
	int end = start;
	while (end < preorder.size() && preorder.at(end) != ',') {
	    ++end;
	}
	string node = preorder.substr(start, end - start + 1);
	if (node == "#," || node == "#") {
	    if (st.empty())
		return false;
	    while (!st.empty() && st.top().second) {
		st.pop();
	    }
	    if (!st.empty())
		st.top().second = true;
	} else {
	    if (st.empty())
		return false;
	    st.emplace(node, false);
	}
	start = end+1;
    }
    return st.empty();
}
