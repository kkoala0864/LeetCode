#include <Solution.h>
#include <iostream>
using namespace std;

int calculate(const string& S, int& idx) {
    if (idx >= S.size()) return 0;
    int local_score(0);
    while (idx < S.size()) {
	if (S.at(idx) == ')') {
	    ++idx;
	    return local_score;
	} else {
	    int ret = calculate(S, ++idx);
	    if (0 == ret) local_score += 1;
	    else if (0 < ret) local_score += 2 * ret;
	}
    }
    return local_score;
}

int Solution::scoreOfParentheses(string S) {
    if (S.empty()) return 0;
    int idx(0);
    return calculate(S, idx);
}
