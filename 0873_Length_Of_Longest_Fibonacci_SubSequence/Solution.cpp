#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::max;
using std::cout;
using std::endl;
using std::unordered_map;

int Solution::lenLongestFibSubseq(vector<int>& A) {
    int size = A.size();
    if (size < 3) return 0;
    int ret = INT_MIN;

    vector<vector<int>> dp(size, vector<int>(size, 0));
    dp.at(1).at(2) = A.at(0) + A.at(1) == A.at(2) ? 3 : 0;
    ret = max(ret, dp.at(1).at(2));

    unordered_map<int, int> loc;
    for (int i = 0 ; i < size ; ++i) loc.emplace(A.at(i), i);

    for (int i = 3 ; i < size ; ++i) {
	for (int j = i - 1 ; j > 0 ; --j) {
	    int first = A.at(i) - A.at(j);
	    if (first >= A.at(j)) continue;
	    if (loc.find(first) != loc.end()) {
		int firstIdx = loc.at(first);
		if (dp.at(firstIdx).at(j) == 0) {
		    dp.at(j).at(i) = 3;
		} else {
		    dp.at(j).at(i) = dp.at(firstIdx).at(j) + 1;
		}
		ret = max(ret, dp.at(j).at(i));
	    }
	}
    }

    return ret == INT_MIN ? -1 : ret;
}
