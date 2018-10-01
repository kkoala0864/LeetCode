#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

bool findLoop(const vector<vector<int>>& graph, const int& curNode,
	vector<int>& Loop, vector<bool>& traverse) {

    if (Loop.at(curNode) == 0 && graph.at(curNode).empty()) {
	Loop.at(curNode) = 2;
	return false;
    }

    if (traverse.at(curNode)) {
	Loop.at(curNode) = 1;
	return true;
    }

    traverse.at(curNode) = true;
    for (const auto& edge : graph.at(curNode)) {
	if (Loop.at(edge) != 2) {
	    if (Loop.at(edge) == 1 || findLoop(graph, edge, Loop, traverse)) {
		Loop.at(curNode) = 1;
		break;
	    }
	}
    }
    traverse.at(curNode) = false;
    if (Loop.at(curNode) == 0) {
	Loop.at(curNode) = 2;
    }
    return Loop.at(curNode) == 2 ? false : true;
}

// Loop vector
// 0 : no check
// 1 : loop
// 2 : sink
vector<int> Solution::eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> res;
    if (graph.empty()) return res;

    int size = graph.size();
    vector<int> Loop(size, 0);

    vector<bool> traverse(size, false);
    for (int i(0) ; i < size ; ++i) {
	if (Loop.at(i) == 0) {
	    if (!findLoop(graph, i, Loop, traverse)) {
		res.emplace_back(i);
	    }
	} else if (Loop.at(i) == 2) {
	    res.emplace_back(i);
	}
    }

    return res;
}

