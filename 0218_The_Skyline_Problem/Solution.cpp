#include <Solution.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if (lhs.first == rhs.first)
	return lhs.second < rhs.second;
    else
	return lhs.first < rhs.first;
}

vector<pair<int, int>> Solution::getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> ret;
    if (buildings.empty()) return ret;

    vector<pair<int, int>> heights;
    for (const auto& building : buildings) {
	heights.emplace_back(building.at(0), -building.at(2));
	heights.emplace_back(building.at(1), building.at(2));
    }
    sort(heights.begin(), heights.end(), cmp);

    multiset<int> maxHeight = {0};
    int prev = 0, cur;
    for (const auto& height : heights) {
	if (height.second < 0) maxHeight.emplace(-height.second);
	else maxHeight.erase(maxHeight.find(height.second));

	cur = *maxHeight.rbegin();
	if (prev != cur) {
	    ret.emplace_back(height.first, cur);
	    prev = cur;
	}
    }

    return ret;
}
