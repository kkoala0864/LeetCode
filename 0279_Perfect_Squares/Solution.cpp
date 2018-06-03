#include <Solution.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

int Solution::numSquares(int n) {
    if (0 >= n) {
	return 0;
    }

    vector<int> table(n + 1, 0);
    int sqrtN = static_cast<int>(sqrt(n));
    for (int i = 1 ; i <= sqrtN ; ++i) {
	table.at(i*i) = 1;
    }

    for (int i = 1 ; i <= n ; ++i) {
	int minCount(INT_MAX);
	if (table.at(i) == 1) {
	    continue;
	}
	for (int j = 1 ; j*j <= i ; ++j) {
	    int count = table.at(j*j) + table.at(i - (j*j));
	    if (count < minCount) {
		minCount = count;
	    }
	}
	table.at(i) = minCount;
    }
    return table.at(n);
}

int Solution::numSquares4SquaresTheory(int n) {
    while (n % 4 == 0) n /= 4;
    if (n % 8 == 7) return 4;
    for (int i = 0 ; (i * i) < n ; ++i) {
	int j = sqrt(n - (i*i));
	if ((i*i + j*j) == n) return !!i + !!j;
    }
    return 3;
}
