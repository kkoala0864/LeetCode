#include <Solution.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

vector<int> Solution::findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> ret;
    int totalCnt(n);
    vector<set<int>> Map(n);
    vector<int> degree(n);
    for (const auto& idx : edges) {
	Map.at(idx.first).emplace(idx.second);
	Map.at(idx.second).emplace(idx.first);
	++degree.at(idx.first);
	++degree.at(idx.second);
    }

    queue<int> remove;
    for (int i = 0 ; i < n ; ++i) {
	if (degree.at(i) == 1) {
	    remove.push(i);
	}
    }

    while (totalCnt > 2) {
	queue<int> nextRemove;
	totalCnt -= remove.size();
	while (!remove.empty()) {
	    int cur = remove.front(); remove.pop();
	    for (const auto& idx : Map.at(cur)) {
		Map.at(idx).erase(cur);
		--degree.at(idx);
		if (degree.at(idx) == 1) {
		    nextRemove.push(idx);
		}
	    }
	    degree.at(cur) = -1;
	}
	remove = move(nextRemove);
    }
    for (int i = 0 ; i < n ; ++i) {
	if (degree.at(i) != -1) {
	    ret.emplace_back(i);
	}
    }
    return ret;
}


