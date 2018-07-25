#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

void dfs(int target, int curFuel, const vector<vector<int>>& stations, int step, int idx, int& MinStep) {
    int nextFuel = curFuel + stations.at(idx).at(1);
    if (nextFuel >= target) {
	MinStep = min(MinStep, step+1);
	return;
    }
    for (int i = idx+1 ; i < stations.size() ; ++i) {
	if (nextFuel >= stations.at(i).at(0)) {
	    dfs(target, nextFuel, stations, step + 1, i, MinStep);
	}
    }
}

int Solution::minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if (startFuel >= target) return 0;

    int MinStep(INT_MAX);
    for (int i = 0 ; i < stations.size() ; ++i) {
	if (stations.at(i).at(0) <= startFuel) {
	    dfs(target, startFuel, stations, 0, i, MinStep);
	}
    }
    return MinStep == INT_MAX ? -1 : MinStep;
}

// dp[j] = max gas of jth times refueling
// dp[j] = max(dp[j-1] + stations.at(i), dp[j]);
int Solution::minRefuelStopsDP(int target, int startFuel, vector<vector<int>>& stations) {
    if (startFuel >= target) return 0;
    vector<int> dp(stations.size()+1, startFuel);

    for (int i = 0 ; i < stations.size() ; ++i) // pass through the station
	for (int j = i+1 ; j > 0 ; --j) // reverse order for 1 Dimension
	    if (dp.at(j-1) >= stations.at(i).at(0))
		dp.at(j) = max(dp.at(j-1) + stations.at(i).at(1), dp.at(j));

    for (int i = 0 ; i <= stations.size() ; ++i)
	if (dp.at(i) >= target)
	    return i;

    return -1;
}

// priorityQueue + greedy
int Solution::minRefuelStopsPQ(int target, int startFuel, vector<vector<int>>& stations) {
    if (startFuel >= target) return 0;
    int i = 0, res;
    priority_queue<int> maxHeap;
    for (res = 0 ; startFuel < target ; ++res) {
	while (i < stations.size() && startFuel >= stations.at(i).at(0)) {
	    maxHeap.emplace(stations.at(i++).at(1));
	}
	if (maxHeap.empty()) return -1;
	startFuel += maxHeap.top(); maxHeap.pop();
    }
    return res;
}
