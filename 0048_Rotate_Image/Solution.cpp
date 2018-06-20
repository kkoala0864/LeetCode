#include <Solution.h>
#include <iostream>

using namespace std;

void Solution::rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    if (1 == size) return;
    int x(0);
    while (x < (size/2)) {
	for (int y = x ; y < (size-x-1) ; ++y) {
	    swap(matrix.at(size-1-x).at(size-1-y), matrix.at(size-1-y).at(x));
	    swap(matrix.at(y).at(size-1-x), matrix.at(size-1-x).at(size-1-y));
	    swap(matrix.at(x).at(y), matrix.at(y).at(size-1-x));
	}
	++x;
    }
}
