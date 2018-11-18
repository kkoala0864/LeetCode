#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;
using std::max;

// dij : maximum length of pair chain until j
int Solution::findLongestChain(vector<vector<int>>& pairs) {
    if (pairs.empty()) return 0;
    sort(pairs.begin(), pairs.end());
    int size = pairs.size();

    vector<int> dp(size , 1);
    for (int j(0) ; j < size ; ++j) {
	int maxVal(1);
	for (int i(0) ; i < j ; ++i) {
	    if (pairs.at(i).at(1) < pairs.at(j).at(0)) {
		maxVal = max(maxVal, dp.at(i) + 1);
	    }
	}
	dp.at(j) = maxVal;
    }
    return dp.at(size-1);
}

int Solution::findLongestChainII(vector<vector<int>>& pairs) {
    if (pairs.empty()) return 0;
    sort(pairs.begin(), pairs.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[1] < rhs[1]; });

    int count(0), end(INT_MIN);
    for (const auto& vec : pairs) {
	if (vec[0] > end) {
	    end = vec[1];
	    ++count;
	}
    }
    return count;
}
