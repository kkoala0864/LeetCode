#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::climbStairs(int n) {
    if (n < 2) {
	return 1;
    }

    int first(1);
    int second(1);
    for (int i = 2 ; i <= n ; ++i) {
	int tmp = second;
	second += first;
	first = tmp;
    }

    return second;
}
