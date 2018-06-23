#include <Solution.h>
#include <iostream>
using namespace std;

void Solution::setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int xSize = matrix.size();
    int ySize = matrix.at(0).size();
    vector<bool> rowV(ySize, false);
    for (int i = 0 ; i < xSize ; ++i) {
	bool rowClear(false);
	for (int j = 0 ; j < ySize ; ++j) {
	    if (matrix.at(i).at(j) == 0) {
		rowClear = true;
		rowV.at(j) = true;
	    }
	}
	if (rowClear) {
	    for (int j = 0 ; j < ySize ; ++j) {
		matrix.at(i).at(j) = 0;
	    }
	}
    }
    for (int i = 0 ; i < ySize ; ++i) {
	if (rowV.at(i)) {
	    for (int x = 0 ; x < xSize ; ++x) {
		matrix.at(x).at(i) = 0;
	    }
	}
    }
}
