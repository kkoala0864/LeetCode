#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    int size = nums.size();
    if (1 == size) return nums.at(0);
    if (2 == size) return max(nums.at(0), nums.at(1));
    vector<int> dp;
    dp.emplace_back(nums.at(0));
    dp.emplace_back(max(nums.at(0), nums.at(1)));

    for (int i = 2 ; i < size ; ++i) {
	dp.emplace_back(max(dp.at(i-1), dp.at(i-2)+nums.at(i)));
    }
    return dp.at(size-1);
}
