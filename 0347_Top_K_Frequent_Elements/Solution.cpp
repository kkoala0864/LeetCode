#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
    vector<int> ret;
    if (nums.empty() || k <= 0) {
	return ret;
    }
    unordered_map<int, int> count;
    for (const auto& idx : nums) {
	++count[idx];
    }

    priority_queue<pair<int, int>> heap;
    for (const auto& idx : count) {
	if (idx.second > 0) {
	    heap.emplace(idx.second, idx.first);
	}
    }

    for (int i = 0 ; i < k ; ++i) {
	ret.emplace_back(heap.top().second);
	heap.pop();
    }
    return ret;
}
