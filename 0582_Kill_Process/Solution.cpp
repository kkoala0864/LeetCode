#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> Solution::killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    vector<int> ret;
    if (pid.empty() || pid.empty()) return ret;
    unordered_map<int, vector<int>> process;
    for (int i = 0 ; i < pid.size() ; ++i) {
	process[ppid.at(i)].emplace_back(pid.at(i));
    }

    queue<int> que;
    que.emplace(kill);
    ret.emplace_back(kill);
    while (!que.empty()) {
	int curProcess = que.front();
	que.pop();
	auto childIter = process.find(curProcess);
	if (childIter != process.end()) {
	    for (int i = 0 ; i < childIter->second.size() ; ++i) {
		que.emplace(childIter->second.at(i));
		ret.emplace_back(childIter->second.at(i));
	    }

	    process.erase(curProcess);
	}
    }
    return ret;
}
