#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::uniquePaths(int m, int n) {
    --m;
    --n;
    if (m < 0 || n < 0) return 0;
    if (m == 0 && n == 0) return 1;
    long long total(1);
    long long divide(1);
    for (int i = 0 ; i < min(m,n) ; ++i) {
	total *= (m+n-i);
	divide *= i+1;
    }
    return total / divide;
}
