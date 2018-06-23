#include <Solution.h>
#include <iostream>

using namespace std;

vector<int> Solution::asteroidCollision(vector<int>& asteroids) {
    vector<int> ret;
    if (asteroids.empty()) return ret;

    for (const auto& idx : asteroids) {
	if (ret.empty() || ret.back() < 0 || (ret.back() > 0 && idx > 0)) {
	    ret.emplace_back(idx);
	} else {
	    int idxSize = -idx;
	    while (!ret.empty() && ret.back() > 0) {
		if (idxSize > ret.back()) {
		    ret.pop_back();
		} else {
		    break;
		}
	    }
	    if (ret.empty() || ret.back() < 0)
		ret.emplace_back(idx);
	    else if (idxSize == ret.back())
		ret.pop_back();
	}
    }
    return ret;
}

