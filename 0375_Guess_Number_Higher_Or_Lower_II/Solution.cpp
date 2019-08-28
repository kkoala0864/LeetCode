#include <Solution.h>
#include <iostream>
#include <vector>

using std::min;
using std::max;
using std::vector;

int recurHelp(vector<vector<int>>& dp, int start, int end) {
    if (start >= end) return 0;
    if (dp.at(start).at(end)) return dp.at(start).at(end);

    int ret(INT_MAX);
    for (int i = start ; i <= end ; ++i) {
	int tmp = i + max(recurHelp(dp, start, i-1), recurHelp(dp, i+1, end));
	ret = min(ret, tmp);
    }
    dp.at(start).at(end) = ret;
    return ret;
}

int Solution::getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    return recurHelp(dp, 1, n);
}
