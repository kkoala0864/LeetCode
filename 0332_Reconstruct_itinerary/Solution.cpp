#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
// Fleury's Algorithm : Find Eulerian Cycle of Graph
void dfs(const string& curLoc, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& locMap, vector<string>& ret) {
    while (!locMap[curLoc].empty()) {
	string nextLoc = locMap[curLoc].top();
	locMap[curLoc].pop();
	dfs(nextLoc, locMap, ret);
    }
    ret.emplace_back(curLoc);
}

vector<string> Solution::findItinerary(vector<pair<string, string>> tickets) {
    vector<string> ret;
    if (tickets.empty()) return ret;
    int size = tickets.size();
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> locMap;
    for (const auto& ticket : tickets)
	locMap[ticket.first].emplace(ticket.second);

    dfs("JFK", locMap, ret);
    reverse(ret.begin(), ret.end());
    return ret;
}
