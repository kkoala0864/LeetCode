#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

void dfs (int height, int x, int y , int m, int n, vector<vector<bool>>& record, vector<vector<int>>& matrix) {
    if ((x < 0 || x >= m) || (y < 0 || y >= n)) {
	return;
    }

    if (height <= matrix.at(x).at(y) && !record.at(x).at(y)) {
	record.at(x).at(y) = true;
	dfs(matrix.at(x).at(y), x-1, y, m, n, record, matrix);
	dfs(matrix.at(x).at(y), x+1, y, m, n, record, matrix);
	dfs(matrix.at(x).at(y), x, y-1, m, n, record, matrix);
	dfs(matrix.at(x).at(y), x, y+1, m, n, record, matrix);
    }
}

vector<pair<int, int>> Solution::pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> loc;
    if (matrix.empty()) {
	return loc;
    }

    int m = matrix.size();
    int n = matrix.at(0).size();
    vector<vector<bool>> PM(m, vector<bool>(n, false));
    vector<vector<bool>> AM(m, vector<bool>(n, false));

    for (int y = 0 ; y < n ; ++y) {
	dfs(0, 0, y, m, n, PM, matrix);
	dfs(0, m-1, y, m, n, AM, matrix);
    }
    for (int x = 0 ; x < m; ++x) {
	dfs(0, x, 0, m, n, PM, matrix);
	dfs(0, x, n-1, m, n, AM, matrix);
    }
    for (int x = 0 ; x < m ; ++x) {
	for (int y = 0 ; y < n ; ++y) {
	    if (PM.at(x).at(y) && AM.at(x).at(y)) {
		loc.emplace_back(x,y);
	    }
	}
    }
    return loc;
}

void bfs(vector<vector<bool>>& record, queue<pair<int, int>>& Queue, vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix.at(0).size();
    vector<vector<int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!Queue.empty()) {
	auto cur = Queue.front();
	int val = matrix.at(cur.first).at(cur.second);
	Queue.pop();
	for (const auto& idx : direct) {
	    int x = cur.first + idx.at(0);
	    int y = cur.second + idx.at(1);
	    if (x >= 0  && x < m && y >=0 && y < n && !record.at(x).at(y) && val <= matrix.at(x).at(y)) {
		record.at(x).at(y) = true;
		Queue.push(make_pair(x,y));
	    }
	}
    }
}

vector<pair<int, int>> Solution::pacificAtlanticBFS(vector<vector<int>>& matrix) {

    vector<pair<int, int>> retLoc;
    if (matrix.empty()) {
	return retLoc;
    }

    int m = matrix.size();
    int n = matrix.at(0).size();
    vector<vector<bool>> PM(m, vector<bool>(n, false)), AM = PM;
    queue<pair<int, int>> PQ, AQ;

    for (int y = 0 ; y < n ; ++y) {
	PM.at(0).at(y) = true;
	PQ.push(make_pair(0, y));
	AM.at(m-1).at(y) = true;
	AQ.push(make_pair(m-1,y));
    }
    for (int x = 0 ; x < m ; ++x) {
	PM.at(x).at(0) = true;
	PQ.push(make_pair(x, 0));
	AM.at(x).at(n-1) = true;
	AQ.push(make_pair(x, n-1));
    }
    bfs(PM, PQ, matrix);
    bfs(AM, AQ, matrix);
    for (int x = 0 ; x < m ; ++x) {
	for (int y = 0 ; y < n ; ++y) {
	    if (PM.at(x).at(y) && AM.at(x).at(y)) {
		retLoc.emplace_back(x, y);
	    }
	}
    }
    return retLoc;
}
