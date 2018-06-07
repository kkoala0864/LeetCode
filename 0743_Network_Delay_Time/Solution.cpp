#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int Solution::networkDelayTime(vector<vector<int>>& times, int N, int K) {
    if (times.empty()) {
	return -1;
    }

    vector<vector<int>> cost(N, vector<int>(N, -1));
    for (const auto& idx : times) {
	cost.at(idx.at(0)-1).at(idx.at(1)-1) = idx.at(2);
    }

    vector<int> min(N, INT_MAX);
    min.at(K-1) = 0;
    queue<int> bfs;
    bfs.push(K-1);

    while (!bfs.empty()) {
	int from = bfs.front();
	bfs.pop();
	for (int i = 0 ; i < N ; ++i) {
	    if (cost.at(from).at(i) >= 0 && i != from) {
		int cur_cost = cost.at(from).at(i) + min.at(from);
		if (min.at(i) > cur_cost) {
		    min.at(i) = cur_cost;
		    bfs.push(i);
		}
	    }
	}
    }
    int ret(0);
    for (const auto& idx : min) {
	if (idx == INT_MAX) {
	    return -1;
	}
	if (idx > ret) {
	    ret = idx;
	}
    }
    return ret;

}

