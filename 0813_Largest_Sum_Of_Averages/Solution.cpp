#include <Solution.h>
#include <iostream>

using std::max;

// dp.at(i).at(j) : largest Sum of Averages i+1 cut A(0) ~ A(j)
double Solution::largestSumOfAverages(vector<int>& A, int K) {
    int size = A.size();
    vector<vector<double>> dp(K, vector<double>(size, 0));

    double Sum = 0, Cnt = 0;
    for (int i = 0 ; i < size ; ++i) {
	Sum += A.at(i);
	++Cnt;
	dp.at(0).at(i) = Sum / Cnt;
    }

    for (int KIdx = 1 ; KIdx < K ; ++KIdx) {
	dp.at(KIdx).at(KIdx) = dp.at(KIdx-1).at(KIdx-1) + A.at(KIdx);
	for (int AIdx = KIdx ; AIdx < size ; ++AIdx) {
	    double LastSum = 0;
	    double LastCnt = 0;
	    double tmp = dp.at(KIdx-1).at(AIdx-1);
	    for (int LastIdx = AIdx ; LastIdx < size ; ++LastIdx) {
		LastSum += A.at(LastIdx);
		++LastCnt;
		dp.at(KIdx).at(LastIdx) = max(dp.at(KIdx).at(LastIdx), tmp + (LastSum / LastCnt));
	    }
	}
    }
    return dp.at(K-1).at(size-1);
}
