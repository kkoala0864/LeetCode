#include <Solution.h>
#include <iostream>
#include <queue>

using namespace std;

int Solution::findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;
    int size = M.size();
    vector<bool> people(size, false);

    int cnt(0);
    for (int i = 0 ; i < size ; ++i) {
	if (people.at(i)) continue;
	++cnt;

	queue<int> circle;
	circle.emplace(i);
	people.at(i) = true;
	M.at(i).at(i) = 0;
	while (!circle.empty()) {
	    int cur = circle.front();
	    circle.pop();
	    for (int j = 0 ; j < size ; ++j) {
		if (M.at(cur).at(j) == 1 && !people.at(j)) {
		    people.at(j) = true;
		    M.at(cur).at(j) = 0;
		    M.at(j).at(cur) = 0;
		    circle.emplace(j);
		}
	    }
	}
    }
    return cnt;
}
