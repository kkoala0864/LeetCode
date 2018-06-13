#include <Solution.h>
#include <iostream>

using namespace std;

void clearBattle (int x, int y, vector<vector<char>>& board) {
    int xSize = board.size();
    int ySize = board.at(0).size();
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (const auto& idx : direction) {
	int curX = x + idx.first;
	int curY = y + idx.second;
	if (curX >= 0 && curX < xSize && curY >=0 && curY < ySize && board.at(curX).at(curY) == 'X') {
	    board.at(curX).at(curY) = '.';
	    clearBattle(curX, curY, board);
	}
    }
}

int Solution::countBattleships(vector<vector<char>>& board) {
    int bCnt(0);
    for (int x = 0 ; x < board.size() ; ++x) {
	for (int y = 0 ; y < board.at(0).size() ; ++y) {
	    if (board.at(x).at(y) == 'X') {
		++bCnt;
		clearBattle(x, y, board);
	    }
	}
    }
    return bCnt;
}

int Solution::countBattleships2(vector<vector<char>>& board) {
    int bCnt(0);
    int xSize = board.size();
    int ySize = board.at(0).size();
    for (int x = 0 ; x < xSize ; ++x) {
	for (int y = 0 ; y < ySize ; ++y) {
	    if (board.at(x).at(y) == 'X') {
		if (x-1 >= 0 && board.at(x-1).at(y) == 'X') continue;
		if (y-1 >= 0 && board.at(x).at(y-1) == 'X') continue;
		++bCnt;
	    }
	}
    }
    return bCnt;
}


