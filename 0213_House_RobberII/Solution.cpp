#include <Solution.h>
#include <iostream>

using namespace std;

int robber(vector<int>& nums, int start, int end) {
    int size = end - start;
    if (0 == size) return 0;
    if (1 == size) return nums.at(start);
    if (2 == size) return max(nums.at(start), nums.at(start+1));
    vector<int> dp;
    dp.emplace_back(nums.at(start));
    dp.emplace_back(max(nums.at(start), nums.at(start+1)));
    for (int i = 2 ; i < size ; ++i) {
	dp.emplace_back(max(dp.at(i-1), dp.at(i-2) + nums.at(start + i)));
    }
    return dp.at(size-1);
}

int Solution::rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    int size = nums.size();
    if (1 == size) return nums.at(0);
    if (2 == size) return max(nums.at(0), nums.at(1));
    return max(robber(nums, 0, size-1), robber(nums, 1, size));
}
