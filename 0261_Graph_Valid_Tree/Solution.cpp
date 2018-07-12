#include <Solution.h>
#include <iostream>

using namespace std;

bool Solution::validTree(int n, vector<pair<int, int>>& edges) {
    if (edges.size() != n-1) return false;
    vector<int> direct(n, 0);
    for (int i = 0 ; i < n ; ++i) {
	direct.at(i) = i;
    }

    for (const auto& edge : edges) {
	int v1 = edge.first;
	int v2 = edge.second;
	while (v1 != direct.at(v1)) v1 = direct.at(v1);
	while (v2 != direct.at(v2)) v2 = direct.at(v2);
	if (v1 == v2) {
	    return false;
	} else {
	    direct.at(v1) = v2;
	}
    }
    return true;
}
