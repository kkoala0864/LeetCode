#include <Solution.h>
#include <iostream>

using std::min;
using std::max;
using std::cout;
using std::endl;

bool square_check(const vector<vector<int>>& grid, int row, int col, int square_size) {
    int col_size = grid.at(0).size();
    int row_size = grid.size();

    if ((row + square_size) >= row_size ||
	    (col  + square_size) >= col_size) {
	return false;
    }

    for (int i = 0 ; i <= square_size ; ++i) {
	if (grid.at(row+i).at(col) == 0) return false;
	if (grid.at(row).at(col+i) == 0) return false;
	if (grid.at(row+square_size).at(col+i) == 0) return false;
	if (grid.at(row+i).at(col+square_size) == 0) return false;
    }
    return true;
}

int Solution::largest1BorderedSquare(vector<vector<int>>& grid) {
    int col_size = grid.at(0).size();
    int row_size = grid.size();
    int ret = 0;

    vector<vector<int>> horizontal(row_size, vector<int>(col_size)), vertical(row_size, vector<int>(col_size));

    for (int i = 0 ; i < row_size ; ++i) {
	for (int j = 0 ; j < col_size ; ++j) {
	    if (1 == grid.at(i).at(j)) {
		horizontal.at(i).at(j) = (j == 0) ? 1 : horizontal.at(i).at(j-1) + 1;
		vertical.at(i).at(j) = (i == 0) ? 1 : vertical.at(i-1).at(j) + 1;
	    }
	}
    }

    for (int i = row_size - 1 ; i >= 0 ; --i) {
	for (int j = col_size - 1 ; j >= 0 ; --j) {
	    int square_size = min(horizontal.at(i).at(j), vertical.at(i).at(j));
	    while (square_size > ret) {
		if ((horizontal.at(i-square_size+1).at(j) >= square_size) &&
			(vertical.at(i).at(j-square_size+1) >= square_size)) {
		    ret = square_size;
		} else {
		    --square_size;
		}
	    }
	}
    }
    return ret * ret;
}
