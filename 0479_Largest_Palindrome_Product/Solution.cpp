#include <Solution.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Solution::largestPalindrome(int n) {
	if (1 == n) {
		return 9;
	}

	long upperBound = pow(10, n) - 1;
	long lowBound = upperBound / 10;

	for (long upper = upperBound ; upper > lowBound ; --upper) {
		string t = to_string(upper);
		long p = stol(t + string(t.rbegin(), t.rend()));
		for (long j = upperBound ; j * j > p ; --j) {
			if (p % j == 0) {
				return p % 1337;
			}
		}
	}
	return 0;
}

