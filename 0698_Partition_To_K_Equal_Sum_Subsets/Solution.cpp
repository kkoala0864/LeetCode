#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::greater;

bool gatherPacket(const int average, vector<bool>& visited, vector<int>& nums, int targetK, int propagate, int curIdx) {
    if (1 == targetK) return true;
    if (propagate > average) return false;
    if (propagate == average) return gatherPacket(average, visited, nums, targetK - 1, 0, 0);
    int size = nums.size();
    for (int i = curIdx ; i < size ; ++i) {
	if (visited.at(i)) continue;
	visited.at(i) = true;
	if (gatherPacket(average, visited, nums, targetK, propagate + nums.at(i), i + 1)) return true;
	visited.at(i) = false;
    }
    return false;
}

bool Solution::canPartitionKSubsets(vector<int>& nums, int k) {
    int Sum(0);
    for (const auto& iter : nums) Sum += iter;
    if ((Sum % k) > 0) return false;
    sort(nums.begin(), nums.end(), greater<int>());

    vector<bool> visited(nums.size(), false);
    return gatherPacket(Sum / k, visited, nums, k, 0, 0);
}
