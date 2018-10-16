#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;
void help(vector<vector<int>>& grid, int& count, const int i, const int j, const int& m, const int& n) {
    ++count;
    grid.at(i).at(j) = 0;
    if (((i+1) < m) && grid.at(i+1).at(j) == 1) help(grid, count, i + 1, j, m, n);
    if (((i-1) >= 0) && grid.at(i-1).at(j) == 1) help(grid, count, i - 1, j, m, n);
    if (((j+1) < n) && grid.at(i).at(j+1) == 1) help(grid, count ,i , j + 1, m, n);
    if (((j-1) >= 0) && grid.at(i).at(j-1) == 1) help(grid, count ,i , j - 1, m, n);
}

int Solution::maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxVal(0);
    int m = grid.size();
    int n = grid.at(0).size();

    for (int i(0) ; i < m ; ++i) {
	for (int j(0) ; j < n ; ++j) {
	    if (grid.at(i).at(j) == 1) {
		int count(0);
		help(grid, count, i, j, m, n);
		if (count > maxVal) maxVal = count;
	    }
	}
    }
    return maxVal;
}
