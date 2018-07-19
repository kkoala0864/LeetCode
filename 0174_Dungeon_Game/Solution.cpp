#include <Solution.h>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// dp[i][j] : current need health
int Solution::calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon.at(0).size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

    dp.at(m).at(n-1) = 1;
    dp.at(m-1).at(n) = 1;

    for (int i = m-1 ; i >= 0 ; --i) {
	for (int j = n-1 ; j >= 0; --j) {
	    dp.at(i).at(j) = min(dp.at(i).at(j+1), dp.at(i+1).at(j)) - dungeon.at(i).at(j);
	    if (dp.at(i).at(j) <= 0) dp.at(i).at(j) = 1;
	}
    }
    return dp.at(0).at(0);
}
