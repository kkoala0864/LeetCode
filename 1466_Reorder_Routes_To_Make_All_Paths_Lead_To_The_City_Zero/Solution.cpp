#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void iterate(vector<vector<int>>& to, vector<vector<int>>& from, vector<bool>& footprint, int& count, int cur) {
	if (-1 == cur || footprint.at(cur)) return;

	footprint.at(cur) = true;

	for (const auto iter : to.at(cur)) {
		if (!footprint.at(iter)) {
			iterate(to, from, footprint, count, iter);
			++count;
		}
	}

	for (const auto iter : from.at(cur)) {
		if (!footprint.at(iter)) {
			iterate(to, from, footprint, count, iter);
		}
	}
	return;
}

int Solution::minReorder(int n, vector<vector<int>>& connections) {
	vector<vector<int>> to(n, vector<int>());
	vector<vector<int>> from(n, vector<int>());
	vector<bool> footprint(n, false);

	for (const auto iter: connections) {
		to.at(iter.at(0)).push_back(iter.at(1));
		from.at(iter.at(1)).push_back(iter.at(0));
	}

	int count(0);
	iterate(to, from, footprint, count, 0);
	return count;
}

