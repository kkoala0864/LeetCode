#include <Solution.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

using std::pair;
using std::min;
using std::max;
using std::queue;
using std::cout;
using std::endl;

int Solution::minimumEffortPath(vector<vector<int>>& heights) {
	int n = heights.size();
	int m = heights[0].size();
	vector<vector<unsigned int>> weights(n, vector<unsigned int>(m, INT_MAX));
	queue<pair<int,int>> que;
	weights[0][0] = 0;

	que.emplace(pair<int, int>(0,0));
	int d[5] = {0,-1,0,1,0};
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		for (int i = 0 ; i < 4 ; ++i) {
			int x = cur.first + d[i];
			int y = cur.second + d[i+1];
			if (x < 0 || x >= n|| y < 0 || y >= m) continue;
			if (weights[cur.first][cur.second] >= weights[x][y]) {
				continue;
			}
			unsigned int absVal = abs(heights[cur.first][cur.second] - heights[x][y]);
			weights[x][y] = min(max(weights[cur.first][cur.second], absVal), weights[x][y]);
			que.emplace(pair<int,int>(x,y));
		}
	}
	return weights[n - 1][m - 1];
}


