#include <Solution.h>
#include <iostream>

using namespace std;


vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    if (matrix.empty()) return ret;
    int m = matrix.size();
    int n = matrix.at(0).size();

    int left(0), up(0), right(n-1), down(m-1), curX(0), curY(0);
    while (left <= right && up <= down) {
	if (curX == up&& curY == left) { // to right
	    while (curY <= (right-1)) {
		ret.emplace_back(matrix.at(curX).at(curY));
		++curY;
	    }
	    ++up;
	} else if (curX == (up-1) && curY == right) { // to down
	    while (curX <= (down-1)) {
		ret.emplace_back(matrix.at(curX).at(curY));
		++curX;
	    }
	    --right;
	} else if (curX == (down+1) && curY == left) { // to up
	    while (curX >= up) {
		ret.emplace_back(matrix.at(curX).at(curY));
		--curX;
	    }
	    ++left;
	    ++curX;
	    ++curY;
	} else if (curX == down && curY == (right+1)) { // to left
	    while (curY >= (left+1)) {
		ret.emplace_back(matrix.at(curX).at(curY));
		--curY;
	    }
	    --down;
	}
    }
    if (ret.size() < (m*n))
	ret.emplace_back(matrix.at(curX).at(curY));
    return ret;
}

vector<int> Solution::spiralOrder2(vector<vector<int>>& matrix) {
    vector<int> ret;
    if (matrix.empty()) return ret;
    int m = matrix.size();
    int n = matrix.at(0).size();

    int left(0), up(0), right(n-1), down(m-1);
    while (left <= right && up <= down) {
	for (const auto& idx : ret) {
	    cout << idx << " ";
	}
	cout << endl;
	for (int i = left ; i <= right ; ++i) {
	    ret.emplace_back(matrix.at(up).at(i));
	}
	++up;
	for (int i = up ; i <= down ; ++i) {
	    ret.emplace_back(matrix.at(i).at(right));
	}
	--right;
	for (int i = right ; i >= left && up <= down ; --i) {
	    ret.emplace_back(matrix.at(down).at(i));
	}
	--down;
	for (int i = down ; i >= up && left <= right ; --i) {
	    ret.emplace_back(matrix.at(i).at(left));
	}
	++left;
    }
    return ret;
}
