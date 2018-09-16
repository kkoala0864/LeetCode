#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

string Solution::decodeAtIndex(string S, int K) {
    long curSize = 0, i(0);
    for (; curSize < K ; ++i) {
	curSize = isdigit(S.at(i)) ? curSize * (S.at(i) - '0') : curSize + 1;
    }

    while (i--) {
	if (isdigit(S.at(i))) {
	    curSize /= (S.at(i) - '0');
	    K %= curSize;
	} else if (K % curSize-- == 0) {
		return string(1, S.at(i));
	}
    }
}
