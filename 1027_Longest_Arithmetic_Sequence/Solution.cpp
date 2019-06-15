#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::max;

int Solution::longestArithSeqLength(vector<int>& A) {
    if (A.empty()) return 0;
    int size = A.size();
    if (1 == size) return 1;
    vector<unordered_map<int, int>> diff(size, unordered_map<int, int>());
    int MaxSize = 2;

    for (int i = 1 ; i < size ; ++i) {
	for (int j = i - 1 ; j >= 0 ; --j) {
	    int diffNo = A.at(i) - A.at(j);
	    const auto iter = diff.at(j).find(diffNo);
	    if (iter == diff.at(j).end()) {
		diff.at(i).emplace(diffNo, 2);
	    } else {
		int cnt = iter->second + 1;
		diff.at(i).emplace(diffNo, cnt);
		MaxSize = max(MaxSize, cnt);
	    }
	}
    }
    return MaxSize;
}
