#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::sort;
using std::cout;
using std::endl;

bool cmp(const string& lhs, const string& rhs) {
    return lhs.size() < rhs.size();
}

bool compare(const string& lhs, const string& rhs) {
    int lhSize = lhs.size();
    int rhSize = rhs.size();

    if (rhSize == lhSize) return false;

    int i = 0, j = 0, diff = 0;
    while (j < rhSize && i < lhSize) {
	if (lhs.at(i) != rhs.at(j)) {
	    ++diff;
	    if (diff > 1) return false;
	} else {
	    ++i;
	}
	++j;
    }
    return true;
}

int Solution::longestStrChain(vector<string>& words) {
    if (words.empty()) return 0;
    int size = words.size();
    int ret = INT_MIN;
    vector<int> dp(size+1, 0);

    sort(words.begin(), words.end(), cmp);
    dp.at(0) = 1;
    for (int i = 1 ; i < size ; ++i) {
	int MaxChain = INT_MIN;
	int iSize = words.at(i).size();
	for (int j = i-1 ; j >= 0 ; --j) {
	    int jSize = words.at(j).size();
	    if (1 < (iSize - jSize)) break;
	    if (compare(words.at(j), words.at(i))) {
		MaxChain = max(MaxChain, dp.at(j) + 1);
	    }
	}
	dp.at(i) = MaxChain == INT_MIN ? 1 : MaxChain;
	ret = max(ret, dp.at(i));
    }
    return ret;
}
