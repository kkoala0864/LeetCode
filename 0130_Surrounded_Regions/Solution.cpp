#include <Solution.h>
#include <iostream>

using namespace std;

bool check(vector<vector<char> >& board, const int& curX, const int& curY,
	const int& x_size, const int& y_size, vector<pair<int,int> >& locRecord) {

	if (((curX - 1) < 0) || ((curY - 1) < 0) || ((curX + 1) >= x_size) || ((curY + 1) >= y_size)){
		return false;
	}

	board[curX][curY] = 'T';
	locRecord.push_back(make_pair(curX, curY));
	cout << locRecord.size() << endl;

	bool left(false);
	if (board[curX-1][curY] == 'X' || board[curX-1][curY] == 'T') {
		left = true;
	} else {
		left = check(board, curX-1, curY, x_size, y_size, locRecord);
	}

	bool right(false);
	if (board[curX+1][curY] == 'X' || board[curX+1][curY] == 'T') {
		right = true;
	} else {
		right = check(board, curX+1, curY, x_size, y_size, locRecord);
	}

	bool up(false);
	if (board[curX][curY-1] == 'X' || board[curX][curY-1] == 'T') {
		up = true;
	} else {
		up = check(board, curX, curY-1, x_size, y_size, locRecord);
	}

	bool down(false);
	if (board[curX][curY+1] == 'X' || board[curX][curY+1] == 'T') {
		down = true;
	} else {
		down = check(board, curX, curY+1, x_size, y_size, locRecord);
	}
	return left && right && up && down;
}

void Solution::solve(vector<vector<char>>& board) {
	int x_size = board.size();
	if (0 == x_size) {
		return;
	}
	int y_size = board.back().size();

	if (y_size == 0) {
		return;
	}
	vector<pair<int, int> > locRecord;
	for (int x = 0 ; x < x_size ; ++x) {
		for (int y = 0 ; y < y_size ; ++y) {
			if ('O' == board[x][y]) {
				bool should_flip = check(board, x, y, x_size, y_size, locRecord);
				if (should_flip) {
					for (const auto& idx : locRecord) {
						board[idx.first][idx.second] = 'X';
					}
				} else {
					for (const auto& idx : locRecord) {
						board[idx.first][idx.second] = 'O';
					}
				}
				locRecord.clear();
			}
		}
	}
}

void connect(vector<vector<char>>& board, const int x, const int y, const int x_size, const int y_size) {
	if (x < 0 || x > x_size || y < 0 || y > y_size) {
		return;
	}

	board[x][y] = 'T';
	if ((0 <= (x-1)) && 'O' == board[x-1][y]) {
		connect(board, x-1, y, x_size, y_size);
	}
	if ((x_size > (x+1)) && 'O' == board[x+1][y]) {
		connect(board, x+1, y, x_size, y_size);
	}
	if ((0 <= (y - 1)) && 'O' == board[x][y-1]) {
		connect(board, x, y-1, x_size, y_size);
	}
	if ((y_size > (y + 1)) && 'O' == board[x][y+1]) {
		connect(board, x, y+1, x_size, y_size);
	}
}

void Solution::solve2(vector<vector<char>>& board) {
	int x_size = board.size();
	if (0 == x_size) {
		return;
	}
	int y_size = board.back().size();

	if (y_size == 0) {
		return;
	}

	for (int x = 0 ; x < x_size ; ++x) {
		if ('O' == board[x][0]) {
			connect(board, x, 0, x_size, y_size);
		}
		if ('O' == board[x][y_size - 1]) {
			connect(board, x, y_size - 1, x_size, y_size);
		}
	}
	for (int y = 0 ; y < y_size ; ++y) {
		if ('O' == board[0][y]) {
			connect(board, 0, y, x_size, y_size);
		}
		if ('O' == board[x_size - 1][y]) {
			connect(board, x_size - 1, y, x_size, y_size);
		}
	}
	for (int x = 0 ; x < x_size ; ++x) {
		for (int y = 0 ; y < y_size ; ++y) {
			if ('O' == board[x][y]) {
				board[x][y] = 'X';
			}
			if ('T' == board[x][y]) {
				board[x][y] = 'O';
			}
		}
	}

}


