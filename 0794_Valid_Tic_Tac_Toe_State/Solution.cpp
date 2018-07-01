#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;

bool Solution::validTicTacToe(vector<string>& board) {
    int XCnt(0), OCnt(0);
    vector<int> rowCnt(3, 0), colCnt(3, 0), diagonal(2,0);
    for (int i = 0 ; i < 3 ; ++i) {
	for (int j = 0 ; j < 3 ; ++j) {
	    int tag(0);
	    if (board.at(i).at(j) == 'X')
		tag = -1;
	    else if (board.at(i).at(j) == 'O')
		tag = 1;

	    if (board.at(i).at(j) == 'X')
		++XCnt;
	    else if (board.at(i).at(j) == 'O')
		++OCnt;

	    if (i == j) diagonal.at(0) += tag;
	    if (i+j == 2) diagonal.at(1) += tag;
	    rowCnt.at(i) += tag;
	    colCnt.at(j) += tag;
	}
    }
    if ((OCnt > XCnt) || ((XCnt - OCnt) > 1)) return false;
    int rowLine(0), colLine(0);
    for (int i = 0 ; i < 3 ; ++i) {
	if (abs(rowCnt.at(i)) == 3) ++rowLine;
	if (rowLine > 1) return false;
	if (abs(colCnt.at(i)) == 3) ++colLine;
	if (colLine > 1) return false;
	if ((rowCnt.at(i) == -3 || colCnt.at(i) == -3) && (XCnt - OCnt != 1)) return false;
	if ((rowCnt.at(i) == 3 || colCnt.at(i) == 3) && (XCnt - OCnt != 0)) return false;
    }
    for (int i = 0 ; i < 2 ; ++i) {
	if ((diagonal.at(0) == -3 || diagonal.at(1) == -3) && XCnt-OCnt != 1) return false;
	if ((diagonal.at(0) == 3 || diagonal.at(1) == 3) && XCnt-OCnt != 0) return false;
    }
    return true;
}
