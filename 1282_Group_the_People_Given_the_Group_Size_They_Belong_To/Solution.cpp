#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<vector<int>> Solution::groupThePeople(vector<int>& groupSizes) {
	vector<vector<int>> ret;
	int totalSize = groupSizes.size();
	for (int i = 0 ; i < totalSize ; ++i) {
		if (0 == groupSizes.at(i)) continue;
		int size = groupSizes.at(i);
		int count = size;
		vector<int> tmp;
		for (int j = i ; 0 < count ; ++j) {
			if (0 == groupSizes.at(j)) continue;
			if (groupSizes.at(j) == size) {
				groupSizes.at(j) = 0;
				tmp.emplace_back(j);
				--count;
			}
		}
		ret.emplace_back(tmp);
	}
	return ret;
}
