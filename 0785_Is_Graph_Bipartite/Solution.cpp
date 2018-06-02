#include <Solution.h>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

void grouping(int node, int groupNo, vector<int>& group, bool& ret, vector<vector<int>>& graph) {
    if (group.at(node) != 0) {
	if (group.at(node) != groupNo) ret = false;
	return;
    }
    group.at(node) = groupNo;
    for (int i = 0 ; i < graph.at(node).size() ; ++i) {
	grouping(graph.at(node).at(i), groupNo == 1 ? 2 : 1, group, ret, graph);
	if (!ret) return;
    }
}

bool Solution::isBipartite(vector<vector<int>>& graph) {
    if (graph.empty()) return false;

    vector<int> group(graph.size(), 0);
    for (int first(0); first < graph.size() ; ++first) {
	if (graph.at(first).empty()) continue;
	bool ret(true);
	if (group.at(first) == 0) {
	    grouping(first, 1, group, ret, graph);
	    if (!ret) return false;
	}
    }
    return true;
}
