#include <Solution.h>
#include <iostream>
#include <climits>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

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

void addQueue(const int key, vector<int>& tmpQueue) {
    int baseline(1);
    for (int i = 0 ; i < 4 ; ++i) {
	int base = baseline * 10;
	int divide = (key / base) * base;
	int addOne = divide + ((key + (1 * baseline)) % base);
	int minusOne = divide + ((key + (9 * baseline)) % base);
	tmpQueue.emplace_back(addOne);
	tmpQueue.emplace_back(minusOne);
	baseline *= 10;
    }
}

int Solution::openLock2(vector<string>& deadends, string target) {
    if (target.empty()) {
	return -1;
    }

    int depth(0);
    queue<int> frontQ, endQ;
    vector<int> visite_f(10000, 0), visite_e(10000, 0);
    for (const auto& idx : deadends) {
	visite_f.at(stoi(idx)) = -1;
	visite_e.at(stoi(idx)) = -1;
    }

    if (visite_f.at(0) == -1 || visite_f.at(stoi(target)) == -1) return -1;
    frontQ.emplace(0);
    visite_f.at(0) = 1;
    endQ.emplace(stoi(target));
    visite_e.at(stoi(target)) = 1;

    while (!frontQ.empty() && !endQ.empty()) {
	if (frontQ.size() > endQ.size()) {
	    swap(frontQ, endQ);
	    swap(visite_f, visite_e);
	}
	queue<int> nextQueue;
	while (!frontQ.empty()) {
	    int current = frontQ.front(); frontQ.pop();
	    vector<int> tmpQueue;
	    addQueue(current, tmpQueue);
	    for (const auto& rotate : tmpQueue) {
		if (visite_e.at(rotate) == 1) return depth + 1;
		if (visite_f.at(rotate) != 0) continue;
		visite_f.at(rotate) = 1;
		nextQueue.emplace(rotate);
	    }
	}
	swap(frontQ, nextQueue);
	++depth;
    }
    return -1;
}
