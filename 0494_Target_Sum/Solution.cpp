#include <Solution.h>
#include <iostream>

using namespace std;

int dfs(const vector<int>& nums, int idx, int sum) {
    if (idx == nums.size()) {
	return sum == 0 ? 1 : 0;
    }
    return dfs(nums, idx+1, sum + nums.at(idx)) + dfs(nums,idx+1, sum-nums.at(idx));
}

int Solution::findTargetSumWays(vector<int>& nums, int S) {
    return dfs(nums, 0, S);
}

// dp[i][j]
// p - n  = S, p+n = Sum n = Sum - p
// p - (Sum - p) = S
// 2p - Sum = S
// p = Sum + S / 2;
// dp[i][j] : How many ways of sum is j of last i element
int Solution::findTargetSumWaysDP(vector<int>& nums, int S) {
    int Sum(0);
    for (const auto& val : nums) {
	Sum += val;
    }
    if (S > Sum) return 0;
    if ((S + Sum) % 2 != 0) return 0;

    int target = (Sum + S) >> 1;
    vector<int> dp(target+1, 0);

    dp.at(0) = 1;
    for (int i = 1 ; i <= nums.size() ; ++i) {
	for (int j = target ; j >= nums.at(i-1) ; --j) {
	    dp.at(j) += dp.at(j - nums.at(i-1));
	}
    }
    return dp.at(target);
}
