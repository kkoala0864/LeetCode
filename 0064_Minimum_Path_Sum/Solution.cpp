#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid.at(0).size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp.at(0).at(0) = grid.at(0).at(0);
    for (int i = 1 ; i < m ; ++i)
	dp.at(i).at(0) = dp.at(i-1).at(0) + grid.at(i).at(0);

    for (int i = 1 ; i < n ; ++i)
	dp.at(0).at(i) = dp.at(0).at(i-1) + grid.at(0).at(i);

    for (int i = 1 ; i < m ; ++i) {
	for (int j = 1 ; j < n ; ++j) {
	    dp.at(i).at(j) = min(dp.at(i-1).at(j) + grid.at(i).at(j), dp.at(i).at(j-1) + grid.at(i).at(j));
	}
    }
    return dp.at(m-1).at(n-1);
}
