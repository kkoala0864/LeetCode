#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::minimumTotal(vector<vector<int>>& triangle) {
    int size = triangle.size();
    vector<int> dp(size, INT_MAX);
    int ret(INT_MAX);
    dp.at(0) = triangle.at(0).at(0);
    for (int i = 0 ; i < size-1 ; ++i) {
	vector<int> tmp(dp);
	for (int j = 0 ; j < triangle.at(i).size() ; ++j) {
	    dp[j] = dp[j] == INT_MAX || dp[j] == tmp[j] ? tmp[j] + triangle[i+1][j] : min(tmp[j] + triangle[i+1][j], dp[j]);
	    dp[j+1] = dp[j+1] == INT_MAX || dp[j+1] == tmp[j+1] ? tmp[j] + triangle[i+1][j+1] : min(tmp[j] + triangle[i+1][j+1], dp[j+1]);
	}
    }
    for (const auto& ele : dp)
	ret = min(ret, ele);
    return ret;
}
