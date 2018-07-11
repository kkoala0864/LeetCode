#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> Solution::findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> ret;
    vector<int> to(2000, 0);
    for (int i = 0 ; i < to.size() ; ++i) {
	to.at(i) = i;
    }

    for (const auto& edge : edges) {
	int x = edge.at(0);
	int y = edge.at(1);

	// if x has been check , the to.at(x) should be x's target
	while (x != to.at(x)) x = to.at(x);
	while (y != to.at(y)) y = to.at(y);
	if (x == y)
	    ret = edge;
	else
	    to.at(x) = y;
    }
    return ret;
}
