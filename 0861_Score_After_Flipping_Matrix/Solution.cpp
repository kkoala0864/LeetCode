#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

int Solution::matrixScore(vector<vector<int>>& A) {
	int rowSize = A[0].size();
	int colSize = A.size();
	int ret(0);
	int base(1);

	for (int i = 0 ; i < colSize ; ++i) {
		int positive(0);
		int flip(0);
		for (int j = 0 ; j < rowSize ; ++j) {
			positive = positive << 1;
			flip = flip << 1;
			positive |= A[i][j];
			flip |= (A[i][j] == 1 ? 0 : 1);
		}
		if (flip > positive) {
			for (int j = 0 ; j < rowSize ; ++j)
				A[i][j] = A[i][j] == 1 ? 0 : 1;
			ret += flip;
		} else {
			ret += positive;
		}
	}
	for (int i = 1 ; i < rowSize ; ++i)
		base = base << 1;
	for (int j = 0 ; j < rowSize ; ++j) {
		int count(0);
		for (int i = 0 ; i < colSize ; ++i) {
			if (1 == A[i][j]) {
				++count;
			}
		}
		int anticount = colSize - count;
		if (anticount > count)
			ret += ((base * anticount) - (base * count));
		base = base >> 1;
	}
	return ret;
}
