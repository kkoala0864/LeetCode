#include <Solution.h>
#include <iostream>
#include <math.h>
#include <stack>
using std::cout;
using std::endl;
using std::min;
using std::stack;
using std::pair;
using std::make_pair;

void help(vector<int>& A, int idx, long& retVal, const long& mod) {
    if (idx >= A.size()) return;
    int curMin(INT_MAX);
    for (int i = idx ; i < A.size() ; ++i) {
	if (curMin > A.at(i)) {
	    curMin = A.at(i);
	}
	retVal += curMin;
	retVal %= mod;
    }
    help(A, idx+1, retVal, mod);
}

int Solution::sumSubarrayMins(vector<int>& A) {
    if (A.empty()) return 0;
    const long mod = 1000000007;
    long retVal(0);
    help(A, 0, retVal, mod);
    return retVal;
}

int Solution::sumSubarrayMinsStack(vector<int>& A) {
    stack<pair<int, int>> st;
    long long int sum(0);
    int size = A.size();

    for (int i = 0 ; i <= size ; ++i) {
	if (st.empty() || ((i < size) && (st.top().first <= A[i]))) {
	    st.emplace(make_pair(A[i], i));
	} else {
	    while (!st.empty() && ((i == size) || (st.top().first > A[i]))) {
		int val = st.top().first;
		int idx = st.top().second;
		st.pop();
		int left, right;
		if (st.empty()) left = idx;
		else left = idx - st.top().second - 1;
		right = i - idx - 1;
		sum += (long long)(left + 1) * (right + 1) * val % 1000000007;
		sum %= 1000000007;
	    }
	    st.emplace(make_pair(A[i], i));
	}
    }
    return sum;
}
