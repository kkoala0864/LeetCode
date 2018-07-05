#include <Solution.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Solution::countNumbersWithUniqueDigits(int n) {
    if (0 == n) return 1;
    if (1 == n) return 10;

    vector<int> dp(n, 0);
    dp.at(0) = 10;
    for (int i = 1 ; i < n ; ++i) {
	int base = 9;
	for (int j = 9 ; j > (10-i-1) ; --j) {
	    base *= j;
	}
	dp.at(i) = dp.at(i-1) + base;
    }
    return dp.at(n-1);
}
