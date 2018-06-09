#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
bool dfs(int start, int node, vector<vector<int>>& graph, vector<bool>& visited) {
    if (node == start) {
	return true;
    }
    visited.at(node) = true;
    if (!graph.at(node).empty()) {
	for (int i = 0 ; i < graph.at(node).size() ; ++i) {
	    if (!visited.at(graph.at(node).at(i)))
		if (dfs(start, graph.at(node).at(i), graph, visited)) return true;
	}
    }
    return false;
}

bool Solution::canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (int i = 0 ; i < prerequisites.size() ; ++i) {
	graph.at(prerequisites.at(i).second).emplace_back(prerequisites.at(i).first);
    }

    for (int i = 0; i < numCourses ; ++i) {
	vector<bool> visited(numCourses, false);
	if (!graph.at(i).empty()) {
	    for (int j = 0 ; j < graph.at(i).size() ; ++j) {
		if (dfs(i, graph.at(i).at(j), graph, visited)) return false;
	    }
	}
    }
    return true;
}

bool Solution::canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> preNum(numCourses, 0);
    queue<int> canTake;
    vector<vector<int>> afterTake(numCourses);

    for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it) {
	++preNum[it->first];
	afterTake[it->second].push_back(it->first);
    }

    int taken = 0;
    for (int i = 0; i < numCourses; ++i) {
	if (preNum[i] == 0) {
	    canTake.push(i);
	}
    }
    while (!canTake.empty()) {
	int cur = canTake.front();
	canTake.pop();
	++taken;
	for (auto it = afterTake[cur].begin(); it != afterTake[cur].end(); ++it) {
	    --preNum[*it];
	    if (preNum[*it] == 0) {
		canTake.push(*it);
	    }
	}
    }
    return taken == numCourses;
}
