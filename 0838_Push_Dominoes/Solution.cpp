#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

string Solution::pushDominoes(string dominoes) {
    int size = dominoes.size();
    vector<int> dp(size, 0);
    int idx(0);
    for (; idx < size ; idx++) {
	if (dominoes.at(idx) == 'R') {
	    int count = 0;
	    ++idx;
	    while (idx < size && dominoes.at(idx) != 'L') {
		if (dominoes.at(idx) == '.') dp.at(idx) = 1; ++count;
		if (dominoes.at(idx) == 'R') count = 0;
		++idx;
	    }
	    if (idx < size) dp.at(idx) = count == 0 ? INT_MAX : count;
	}
    }

    idx = size - 1;
    for (; idx >= 0 ; idx--) {
	if (dominoes.at(idx) == 'L') {
	    if (dp.at(idx) == 0) {
		while (--idx >= 0) {
		    if (dominoes.at(idx) == 'L') {
			++idx;
			break;
		    }
		    dp.at(idx) = -1;
		}
	    } else if (dp.at(idx) == INT_MAX) {
		dp.at(idx) = 0;
		continue;
	    } else {
		int Allstep = dp.at(idx);
		dp.at(idx) = 0;
		int step = (Allstep / 2);
		for (int i = 0 ; i < step ; ++i) dp.at(--idx) = -1;
		if (Allstep & 1) dp.at(--idx) = 0;
	    }
	}
    }
    string ret;
    for (int i = 0 ; i < size ; ++i) {
	if (dp.at(i) == -1 || dp.at(i) > 1) {
	    ret.push_back('L');
	} else if (dp.at(i) == 0) {
	    ret.push_back(dominoes.at(i));
	} else if (dp.at(i) == 1) {
	    ret.push_back('R');
	}
    }
    return ret;
}
