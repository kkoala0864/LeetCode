#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;
using std::max;

// dp[i] : max sum of A[0] ~ A[i]
// transition : dp[i] = max { dp[i-k] + k * max{A[i-k+1] ~ A[i]} }
int Solution::maxSumAfterPartitioning(vector<int>& A, int K) {
    int size = A.size();
    vector<int> dp(size+1, 0);
    for (int i = 1 ; i <= size ; ++i) {
	int m = INT_MIN;
	for (int j = 1 ; j <= K && i >= j ; ++j) {
	     m = max(m, A[i-j]);
	     dp[i] = max(dp[i], dp[i-j] + j * m);
	}
    }
    return dp[size];
}
