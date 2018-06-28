#include <Solution.h>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long long> windows;
    for (int i = 0 ; i < nums.size() ; ++i) {
	if (i > k) windows.erase(nums.at(i - k - 1)); // i and j at most k
	auto pos = windows.lower_bound(((long long)nums.at(i) - (long long)t));
	if (pos != windows.end() && (*pos - nums.at(i)) <= t) return true;
	windows.emplace((long long)nums.at(i));
    }
    return false;
}

bool Solution::containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
    if(nums.size() < 2) return false;
    vector<pair<long, int>> value;
    for (int i = 0; i < nums.size(); ++i)
	value.push_back(pair<long, int>(nums[i], i));

    sort(value.begin(), value.end());

    for (int i = nums.size() - 1; i >= 1; --i) {
	for (int j = i - 1; j >= 0; --j) {
	    if (value[i].first - value[j].first > t) break;
	    else if (abs(value[i].second - value[j].second) <= k) return true;
	    else continue;
	}
    }
    return false;
}
