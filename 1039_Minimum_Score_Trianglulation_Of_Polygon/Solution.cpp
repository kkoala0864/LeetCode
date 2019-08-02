#include <Solution.h>
#include <iostream>
using std::min;
using std::cout;
using std::endl;

int recurHelp(vector<int>& A, int start, int end, vector<vector<int>>& dp) {
    int res = 0;
    int size = A.size();
    //if (dp.at(start).at(end)) return dp.at(start).at(end);
    for (int i = (start + 1) % size ; i != end ; i = (i + 1) % size) {
	res = min(res == 0 ? INT_MAX : res, recurHelp(A, start, i, dp) + A.at(start) * A.at(i) * A.at(end) + recurHelp(A, i, end, dp));
    }
    dp.at(start).at(end) = res;
    return res;
}

int Solution::minScoreTriangulation(vector<int>& A) {
    vector<vector<int>> dp(50, vector<int>(50, 0));
    return recurHelp(A, 0, A.size()-1, dp);
}
