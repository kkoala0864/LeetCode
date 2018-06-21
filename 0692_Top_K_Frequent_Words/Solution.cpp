#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct CompareByFirst {
    constexpr bool operator()(pair<int, string> const & a,
	    pair<int, string> const & b) const noexcept
    {
	return a.first < b.first || (a.first == b.first && (a.second > b.second || (a.second == b.second && a.second.size() > b.second.size())));
    }
};

vector<string> Solution::topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> hash;
    for (const auto& idx : words) {
	if (hash.find(idx) == hash.end())
	    hash.emplace(idx, 1);
	else
	    ++hash.at(idx);
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, CompareByFirst> maxHeap;
    for (const auto& idx : hash) {
	maxHeap.emplace(idx.second, idx.first);
    }

    vector<string> ret;
    while (k-- > 0) {
	ret.emplace_back(maxHeap.top().second);
	maxHeap.pop();
    }
    return ret;
}
