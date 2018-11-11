#include <Solution.h>
#include <iostream>
using std::min;

int Solution::minFallingPathSum(vector<vector<int>>& A) {
    int m = A.size(), n = A.at(0).size();
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0 ; i < n ; ++i) {
	dp.at(0).at(i) = A.at(0).at(i);
    }

    for (int i = 1 ; i < m ; ++i) {
	for (int j(0) ; j < n ; ++j) {
	    int one = (j-1) >= 0 ? min(dp.at(i-1).at(j-1), dp.at(i-1).at(j)) : dp.at(i-1).at(j);
	    int two = (j+1) < n ? min(dp.at(i-1).at(j), dp.at(i-1).at(j+1)) : dp.at(i-1).at(j);
	    dp.at(i).at(j) = min(one, two) + A.at(i).at(j);
	}
    }

    int res(INT_MAX);
    for (int i = 0 ; i < n ; ++i) {
	res = min(res, dp.at(m-1).at(i));
    }

    return res;
}
