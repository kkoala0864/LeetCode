#include <Solution.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int Solution::countPrimes(int n) {
    if (n < 3) return 0;

    vector<bool> flag(n, false);
    int count = n / 2;

    for (unsigned int i = 3; i * i < n; i += 2 ) {
	if (flag[i]) continue;

	for (unsigned int j = i * i ; j < n ; j += i * 2 ) {
	    if (!flag[j])
		count--;
	    flag[j] = true;
	}
    }

    return count;
}
