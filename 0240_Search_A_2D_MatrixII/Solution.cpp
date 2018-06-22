#include <Solution.h>
#include <iostream>

using namespace std;

bool yBinSearch(int x, vector<vector<int>>& matrix, int target) {
    int yStart(0), yEnd(matrix.at(0).size()-1);
    while (yEnd >= yStart) {
	int mid = (yEnd + yStart) / 2;
	if (matrix.at(x).at(mid) > target) {
	    yEnd = mid - 1;
	} else if (matrix.at(x).at(mid) < target) {
	    yStart = mid + 1;
	} else {
	    return true;
	}
    }
    return false;
}

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
    int xSize = matrix.size();
    for (int x = 0 ; x < xSize ; ++x) {
	if (matrix.at(x).at(0) <= target) {
	    if (yBinSearch(x, matrix, target)) {
		return true;
	    }
	}
    }
    return false;
}

bool Solution::searchMatrix2(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    if (matrix.at(0).empty()) return false;

    int xSize = matrix.size();
    int ySize = matrix.at(0).size();
    int x = 0, y = ySize -1;
    while (x < xSize && y >= 0) {
	if (matrix.at(x).at(y) == target) return true;
	else if (matrix.at(x).at(y) < target) ++x;
	else --y;
    }
    return false;
}

