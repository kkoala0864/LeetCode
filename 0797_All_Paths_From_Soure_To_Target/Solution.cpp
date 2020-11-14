#include <Solution.h>
#include <iostream>

void dfs(const int curNode, vector<int>& curPath, vector<vector<int>>& graph, vector<vector<int>>& retPath) {
	if ((graph.size() - 1) == curNode) {
		retPath.emplace_back(curPath);
		return;
	}

	for (const auto iter : graph.at(curNode)) {
		curPath.emplace_back(iter);
		dfs(iter, curPath, graph, retPath);
		curPath.pop_back();
	}
}

vector<vector<int>> Solution::allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int>> retPath;
	vector<int> curPath;
	curPath.emplace_back(0);
	dfs(0, curPath, graph, retPath);
	return retPath;
}
