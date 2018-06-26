#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int Solution::findLength(vector<int>& A, vector<int>& B) {
    int ret(0);
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    for (int i = 0 ; i < A.size() ; ++i) {
	for (int j = 0 ; j < B.size() ; ++j) {
	    if (A.at(i) == B.at(j)) {
		dp.at(i+1).at(j+1) = dp.at(i).at(j) + 1;
	    }
	    ret = max(ret, dp.at(i+1).at(j+1));
	}
    }
    return ret;
}

