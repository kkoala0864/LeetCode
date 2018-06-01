#include <Solution.h>
#include <iostream>
#include <climits>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void addToQueue(const string& current, int step, list<pair<string, int>>& rotation, unordered_map<string, int>& history) {
    size_t size = current.size();
    for (size_t idx = 0 ; idx < size ; ++idx) {
	int number = current.at(idx) - '0';
	string tmp(current);
	tmp.at(idx) = ((number + 1) % 10) + '0';
	if (0 == history[tmp]) {
	    rotation.emplace_back(make_pair(tmp, step + 1));
	    history[tmp] = 1;
	}
	tmp.at(idx) = ((number + 9) % 10) + '0';
	if (0 == history[tmp]) {
	    rotation.emplace_back(make_pair(tmp, step + 1));
	    history[tmp] = 1;
	}
    }
}

int Solution::openLock(vector<string>& deadends, string target) {
    if (target.empty()) {
	return -1;
    }

    list<pair<string, int>> rotation;
    unordered_map<string, int> history;
    int minStep(INT_MAX);

    for (const auto& idx : deadends) {
	history[idx] = -1;
    }
    rotation.emplace_back(make_pair(target, 0));

    while (!rotation.empty()) {
	string current = rotation.front().first;
	int step = rotation.front().second;
	rotation.pop_front();
	if (current == "0000") {
	    return step;
	} else {
	    addToQueue(current, step, rotation, history);
	}
    }
    return -1;
}
