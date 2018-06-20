#include <Solution.h>
#include <iostream>
#include <unordered_map>

using namespace std;

bool Solution::isValidSudoku(vector<vector<char>>& board) {
    int xSize = 9;
    int ySize = 9;
    for (int x = 0 ; x < xSize ; ++x) {
	vector<int> checkBoard(9, 0);
	for (int y = 0 ; y < ySize ; ++y) {
	    if (board.at(x).at(y) != '.') {
		if (checkBoard.at(board.at(x).at(y) - '1') > 0)
		    return false;
		else
		    ++checkBoard.at(board.at(x).at(y) - '1');
	    }
	}
    }

    for (int y = 0 ; y < ySize ; ++y) {
	vector<int> checkBoard(9, 0);
	for (int x = 0 ; x < xSize ; ++x) {
	    if (board.at(x).at(y) != '.') {
		if (checkBoard.at(board.at(x).at(y) - '1') > 0)
		    return false;
		else
		    ++checkBoard.at(board.at(x).at(y) - '1');
	    }
	}
    }

    for (int x = 0 ; x < xSize ; x+=3) {
	for (int y = 0 ; y < ySize ; y+=3) {
	    vector<int> check(9, 0);
	    for (int i = x ; i < x+3 ; ++i) {
		if (board.at(i).at(y) != '.') {
		    if (check.at(board.at(i).at(y) - '1') > 0)
			return false;
		    else
			++check.at(board.at(i).at(y) - '1');
		}
		if (board.at(i).at(y+1) != '.') {
		    if (check.at(board.at(i).at(y+1) - '1') > 0)
			return false;
		    else
			++check.at(board.at(i).at(y+1) - '1');
		}
		if (board.at(i).at(y+2) != '.') {
		    if (check.at(board.at(i).at(y+2) - '1') > 0)
			return false;
		    else
			++check.at(board.at(i).at(y+2) - '1');
		}
	    }
	}
    }
    return true;
}
