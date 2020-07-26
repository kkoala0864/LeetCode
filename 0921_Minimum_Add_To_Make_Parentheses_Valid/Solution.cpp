#include <Solution.h>
#include <iostream>

int Solution::minAddToMakeValid(string S) {
	int leftCnt(0);
	int count(0);

	for (int i = 0 ; i < S.size() ; ++i) {
		if (S.at(i) == '(') {
			++leftCnt;
		} else {
			if (0 == leftCnt) {
				++count;
			} else {
				--leftCnt;
			}
		}
	}
	if (leftCnt) {
		count += leftCnt;
	}

	return count;
}
