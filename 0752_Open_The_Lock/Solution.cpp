#include <Solution.h>
#include <iostream>
#include <climits>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void addToQueue(const int current, const int step, list<pair<int, int>>& rotation, vector<int>& history) {
    int baseline(1);
    for (int i = 0 ; i < 4 ; ++i) {
	int base = baseline * 10;
	int divide = (current / base) * base;
	int addOne = divide + ((current + (1 * baseline)) % base);
	int minusOne = divide + ((current + (9 * baseline)) % base);
	if (history[addOne] == 0) {
	    rotation.emplace_back(make_pair(addOne, step + 1));
	    history[addOne] = 1;
	}
	if (history[minusOne] == 0) {
	    rotation.emplace_back(make_pair(minusOne, step + 1));
	    history[minusOne] = 1;
	}
	baseline *= 10;
    }
}

int Solution::openLock(vector<string>& deadends, string target) {
    if (target.empty()) {
	return -1;
    }

    list<pair<int, int>> rotation;
    vector<int> history(10000, 0);
    int iTarget = stoi(target);

    for (const auto& idx : deadends) {
	history[stoi(idx)] = -1;
    }
    rotation.emplace_back(make_pair(iTarget, 0));

    while (!rotation.empty()) {
	int current = rotation.front().first;
	int step = rotation.front().second;
	rotation.pop_front();
	if (current == 0) {
	    return step;
	} else {
	    addToQueue(current, step, rotation, history);
	}
    }
    return -1;
}
