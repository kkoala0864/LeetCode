#include <Solution.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> Solution::findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> ret;
    vector<vector<int>>	outComeByMe(numCourses);
    vector<int> inCome(numCourses);
    for (const auto& dep : prerequisites) {
	outComeByMe.at(dep.second).emplace_back(dep.first);
	++inCome.at(dep.first);
    }

    queue<int> bfs;
    for (int i = 0 ; i < numCourses ; ++i) {
	if (inCome.at(i) == 0) {
	    bfs.push(i);
	}
    }

    while (!bfs.empty()) {
	int node = bfs.front();
	ret.emplace_back(node);
	bfs.pop();
	for (const auto& idx : outComeByMe.at(node)) {
	    if (0 == --inCome.at(idx)) bfs.push(idx);
	}
    }

    if (ret.size() == numCourses) {
	return ret;
    } else {
	return vector<int>();
    }
}

