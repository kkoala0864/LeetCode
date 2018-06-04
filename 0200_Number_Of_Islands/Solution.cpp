#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int Solution::numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
	return 0;

    int islandCnt(0);
    int row = grid.size();
    int col = grid.back().size();

    queue<pair<int, int>> location;
    for (int i = 0 ; i < row ; ++i) {
	for (int j = 0 ; j < col ; ++j) {
	    if (grid.at(i).at(j) == '1') {
		grid.at(i).at(j) = 'Z';
		location.push(make_pair(i,j));
		while (!location.empty()) {
		    int x = location.front().first;
		    int y = location.front().second;
		    location.pop();
		    if ((x - 1 >= 0) && grid.at(x-1).at(y) == '1') {
			grid.at(x-1).at(y) = 'Z';
			location.push(make_pair(x-1,y));
		    }
		    if ((x + 1 < row) && grid.at(x+1).at(y) == '1') {
			grid.at(x+1).at(y) = 'Z';
			location.push(make_pair(x+1,y));
		    }
		    if ((y - 1 >= 0) && grid.at(x).at(y-1) == '1') {
			grid.at(x).at(y-1) = 'Z';
			location.push(make_pair(x,y-1));
		    }
		    if ((y + 1 < col) && grid.at(x).at(y+1) == '1') {
			grid.at(x).at(y+1) = 'Z';
			location.push(make_pair(x,y+1));
		    }
		}
		++islandCnt;
	    }
	}
    }
    return islandCnt;
}

