#include <Solution.h>
#include <iostream>

using std::max;

int Solution::maxTurbulenceSize(vector<int>& A) {
    int size = A.size();
    if (size < 2) return size;

    int ret = INT_MIN;
    vector<int> dp(size, 0);
    dp.at(0) = 1;
    dp.at(1) = A.at(1) == A.at(0) ? 1 : 2;
    ret = max(ret, dp.at(1));
    for (int i = 2 ; i < size ; ++i) {
	int first = A.at(i-2), second = A.at(i-1), three = A.at(i);
	if (((first < second) && (three < second)) ||
	   ((first > second) && (three > second))) {
	    dp.at(i) = dp.at(i-1) + 1;
	} else {
	    dp.at(i) = three == second ? 1 : 2;
	}
	ret = max(ret, dp.at(i));
    }
    return ret;
}
