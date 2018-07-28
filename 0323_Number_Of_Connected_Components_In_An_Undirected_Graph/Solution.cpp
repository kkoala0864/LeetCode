#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int Solution::countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> groupFlag(n, -1);
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (const auto& edge : edges) {
	matrix.at(edge.first).at(edge.second) = 1;
	matrix.at(edge.second).at(edge.first) = 1;
    }

    int groupCnt(0);
    for (int i = 0 ; i < n ; ++i) {
	if (groupFlag.at(i) == -1) {
	    queue<int> bfs;
	    bfs.emplace(i);
	    ++groupCnt;
	    groupFlag.at(i) = groupCnt;
	    while (!bfs.empty()) {
		int val = bfs.front(); bfs.pop();
		for (int i = 0 ; i < n ; ++i) {
		    if (matrix.at(val).at(i) == 1 && groupFlag.at(i) == -1) {
			groupFlag.at(i) = groupCnt;
			bfs.emplace(i);
		    }
		}
	    }
	}
    }
    return groupCnt;
}

// path Compression
int Solution::countComponentsPC(int n, vector<pair<int, int>>& edges) {
    vector<int> path(n);
    for (int i = 0 ; i < n ; ++i) {
	path.at(i) = i;
    }

    int res = n;
    for (const auto& edge : edges) {
	int v1 = edge.first;
	int v2 = edge.second;
	while (v1 != path.at(v1)) v1 = path.at(v1) = path.at(path.at(v1));
	while (v2 != path.at(v2)) v2 = path.at(v2) = path.at(path.at(v2));

	if (v1 != v2) {
	    --res;
	    path.at(v2) = v1;
	}
    }

    return res;
}
