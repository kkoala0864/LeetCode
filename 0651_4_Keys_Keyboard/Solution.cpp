#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
int Solution::maxA(int N) {
    vector<int> dp(N+1);

    for (int i = 1 ; i <= N ; ++i) {
	dp.at(i) = i;
	for (int x = 1 ; x < i - 2 ; ++x) { // A number 1 ~ (i-3) : i-3 means at least copy once
	    dp.at(i) = max(dp.at(i), dp.at(x) * (i - x - 1));
	}
    }
    return dp.at(N);
}
