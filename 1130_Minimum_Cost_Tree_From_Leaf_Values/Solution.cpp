#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;
using std::min;

int Solution::mctFromLeafValues(vector<int>& arr) {
	int ret(0);
	stack<int> st;
	st.push(INT_MAX);
	for (const auto iter : arr) {
		if (iter < st.top()) {
			st.push(iter);
		} else {
			while (iter > st.top()) {
				int victim = st.top();
				st.pop();
				ret += victim * min(st.top(), iter);
			}
			st.push(iter);
		}
	}
	while (st.size() > 2) {
		int victim = st.top();
		st.pop();
		ret += victim * st.top();
	}
	return ret;
}
