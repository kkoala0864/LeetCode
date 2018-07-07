#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;
//
// dp[i] = (k-1) * dp.at(i-1) + (k-1) * dp.at(i-2)
//       = last two different + last two same
int Solution::numWays(int n, int k) {
    vector<int> dp(n+1, 0);
    dp.at(0) = 0;
    dp.at(1) = k;
    for (int i = 2 ; i <= n ; ++i) {
	dp.at(i) = (k-1) * (dp.at(i-1) + dp.at(i-2));
    }
    return dp.at(n) + dp.at(n-1);
}
