#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::cout;
using std::endl;
using std::max;
using std::unordered_map;

int traverse(const unordered_map<int, int>& maxStep, int start, const int& target, int minStep) {
    if (maxStep.at(start) >= target) return minStep;

    int localMax = INT_MIN;
    int localStart = 0;
    for (int i = maxStep.at(start) ; i > start ; --i) {
	if ((maxStep.find(i) != maxStep.end()) && (maxStep.at(i) > start)) {
	    if (maxStep.at(i) > localMax) {
		localMax = maxStep.at(i);
		localStart = i;
	    }
	}
    }

    if (localMax == INT_MIN) return -1;
    else return traverse(maxStep, localStart, target, minStep+1);
}

int Solution::videoStitching(vector<vector<int>>& clips, int T) {
    if (clips.empty()) return -1;
    unordered_map<int, int> maxStep;
    for (const auto iter : clips) {
	if (maxStep.find(iter.at(0)) != maxStep.end())
	    maxStep[iter.at(0)] = max(maxStep[iter.at(0)], iter.at(1));
	else
	    maxStep[iter.at(0)] = iter.at(1);
    }

    if (maxStep.find(0) == maxStep.end()) return -1;
    return traverse(maxStep, 0, T, 1);
}
