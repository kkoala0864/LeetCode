#include <Solution.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Solution::nthSuperUglyNumber(int n, vector<int>& primes) {

    if (1 == n)
	return 1;
    size_t primeSize = primes.size();
    vector<int> result(1,1);
    vector<int> idx(primeSize, 0);

    for (int uglyCnt = 1 ; uglyCnt < n ; ++uglyCnt) {
	int minNumber = INT_MAX;
	for (int pCnt = 0 ; pCnt < primeSize ; ++pCnt) {
	    minNumber = min(minNumber, result[idx[pCnt]] * primes[pCnt]);
	}
	for (int pCnt = 0 ; pCnt < primeSize ; ++pCnt) {
	    if (minNumber == primes[pCnt] * result[idx[pCnt]]) {
		++idx[pCnt];
	    }
	}
	result.push_back(minNumber);
    }
    return result.back();

}

