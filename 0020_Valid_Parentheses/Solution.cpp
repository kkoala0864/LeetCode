#include <Solution.h>
#include <iostream>
#include <stack>

using namespace std;
bool Solution::isValid(string s) {
    stack<char> st;
    for (int i = 0 ; i < s.size() ; ++i) {
	if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
	    st.emplace(s.at(i));
	} else {
	    if (s.at(i) == ')') {
		if (!st.empty() && st.top() == '(') st.pop();
		else return false;
	    } else if (s.at(i) == '}') {
		if (!st.empty() && st.top() == '{') st.pop();
		else return false;
	    } else {
		if (!st.empty() && st.top() == '[') st.pop();
		else return false;
	    }
	}
    }
    return st.empty();
}

