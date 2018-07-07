#include <Solution.h>
#include <iostream>

using namespace std;

// dp[i][j] : the i row end with j color min cost
// dp[i][j] = min(dp[i-1][i != j] + cost.at(i).(j));
int Solution::minCost(vector<vector<int>>& costs) {
    int size = costs.size();
    vector<vector<int>> dp(size, vector<int>(3, INT_MAX));
    for (int i = 0 ; i < 3 ; ++i) {
	dp.at(0).at(i) = costs.at(0).at(i);
    }

    for (int i = 1 ; i < size ; ++i) {
	for (int j = 0 ; j < 3 ; ++j) {
	    for (int k = 0 ; k < 3 ; ++k) {
		if (k != j) {
		    dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(k) + costs.at(i).at(j));
		}
	    }
	}
    }

    int MinCost(INT_MAX);
    for (int i = 0 ; i < 3 ; ++i) {
	MinCost = min(MinCost, dp.at(size-1).at(i));
    }
    return MinCost;
}
