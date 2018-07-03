#include <Solution.h>
#include <iostream>

using namespace std;

void checkArith(vector<int>& A, int start, int& Cnt) {
    int iter = start;
    int diff = A.at(start) - A.at(start+1);
    while (iter < A.size()-1) {
	if (A.at(iter) - A.at(iter+1) != diff)
	    return;
	if ((iter - start) > 0) {
	    ++Cnt;
	}
	++iter;
    }
}

int Solution::numberOfArithmeticSlices(vector<int>& A) {
    if (A.size() < 3) {
	return 0;
    }
    int Cnt(0);
    for (int start = 0 ; start < A.size() - 2 ; ++start) {
	checkArith(A, start, Cnt);
    }
    return Cnt;

}
