#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;

int Solution::integerBreak(int n) {
    if (n < 2) return 0;
    vector<int> dp(n+1, 0);
    dp.at(2) = 1;
    for (int i = 3 ; i <= n ; ++i) {
	for (int j = 2 ; j <= (i/2)+1 ; ++j) {
	    dp.at(i) = max(dp.at(i), j * dp.at(i-j));
	    dp.at(i) = max(dp.at(i), j * (i - j));
	}
    }
    return dp.at(n);
}
