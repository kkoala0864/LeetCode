#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Solution::minSteps(int n) {
    if (1 == n) return 0;
    vector<int> dp(n+1);
    for (int i = 1 ; i <= n ; ++i) {
	dp.at(i) = i;
	for (int j = 2 ; j <= i ; ++j) {
	    if (0 == i % j) {
		dp.at(i) = min(dp.at(i), dp.at(j) + i / j);
	    }
	}
    }
    return dp.at(n);
}

int Solution::minSteps2(int n) {
    if (1 == n) return 0;
    int res(0);
    for (int i = 2 ; i <= n ; ++i) {
	while (n % i == 0) {
	    res += i;
	    n /= i;
	}
    }
    return res;
}
