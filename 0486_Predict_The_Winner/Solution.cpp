#include <Solution.h>
#include <iostream>
using std::max;
/*
 * dp[i][j] : player1 can get maximum value from nums[i] to nums[j]
 *
 * player1 can choose value nums[i] or nums[j] from nums[i][j]
 * player2 would take rest of nums element and player1 would take maximum of rest of nums element
 * so, player1 maximum number :
 *
 * dp[i][j] = max(sum[i+1][j] - dp[i+1][j] + nums[i], sum[i][j-1] - dp[i][j-1] + nums[j])
 *          = max(sum[i][j] - dp[i+1][j], sum[i][j] - dp[i][j-1])
 *
 * sum[i+1][j] - dp[i+1][j] : if player1 take nums[i], player2 would take maximum value (dp[i+1][j]),
 *                          so sum[i+1][j] - dp[i+1][j] is player1 can take rest of value
 *
 * dp'[i][j] is diff of player1 value and player2 value
 * dp'[i][j] = dp[i][j] - (sum[i][j] - dp[i][j]) = 2 * dp[i][j] - sum[i][j]
 *           = 2 * max(sum[i][j] - dp[i+1][j], sum[i][j] - dp[i][j-1]) - sum[i][j]
 *           = max(sum[i][j] - 2 * dp[i+1][j], sum[i][j] - 2 * dp[i][j-1])
 *           = max(sum[i][j] - dp'[i+1][j] - sum[i+1][j], sum[i][j] - dp'[i][j-1] - sum[i][j-1])
 *           = max(nums[i] - dp'[i+1][j], nums[j] - dp'[i][j-1])
 *
 * dp'[i][j] = max(nums[i] - dp'[i+1][j], nums[j] - dp'[i][j-1])
 */

bool Solution::PredictTheWinner(vector<int>& nums) {
    unsigned int size = nums.size();
    vector<vector<int>> dp(size, vector<int>(size));
    for (int i = 0 ; i < size ; ++i) {
	dp.at(i).at(i) = nums.at(i);
    }

    for (int j = 1 ; j < size ; ++j) {
	for (int i = 0 ; i < size - j ; ++i) {
	    dp.at(i).at(i+j) = max(nums.at(i) - dp.at(i+1).at(i+j), nums.at(i+j) - dp.at(i).at(i+j-1));
	}
    }

    return dp.at(0).at(size-1) >= 0;
}
