#include <Solution.h>
#include <iostream>

using std::pair;

const vector<pair<int, int>> offset = {
	{-1, -1}, {0, -1},
	{1, -1}, {-1, 0},
	{1, 0}, {-1, 1},
	{0, 1}, {1, 1}
};

int checkMine(const pair<int, int>& index, vector<vector<char>>& board, int x, int y, vector<pair<int, int>>& queue) {
	vector<pair<int, int>> local;

	int mineCount(0);
	for (const auto iter : offset) {
		int i = index.first + iter.first;
		int j = index.second + iter.second;
		if (i < 0 || i >= x || j < 0 || j >= y) continue;
		if (board[i][j] == 'M') ++mineCount;
		if (board[i][j] == 'E') local.emplace_back(pair<int, int>(i, j));

	}
	if (0 == mineCount)
		for (auto iter : local)
			queue.emplace_back(iter);
	return mineCount;
}

vector<vector<char>> Solution::updateBoard(vector<vector<char>>& board, vector<int>& click) {
	if (board[click.at(0)][click.at(1)] == 'M') {
		board[click.at(0)][click.at(1)] = 'X';
		return board;
	}

	vector<pair<int, int>> queue;
	int x = board.size();
	int y = board.at(0).size();
	queue.emplace_back(pair<int, int>(click.at(0), click.at(1)));

	while(!queue.empty()) {
		auto iter = queue.back();
		queue.pop_back();
		int mineSize = checkMine(iter, board, x, y, queue);
		if (mineSize > 0) {
			board[iter.first][iter.second] = '0' + mineSize;
		} else {
			board[iter.first][iter.second] = 'B';
		}
	}
	return board;
}
