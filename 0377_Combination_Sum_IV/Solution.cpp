#include <Solution.h>
#include <iostream>

using std::max;
using std::cout;
using std::endl;

int Solution::combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp.at(0) = 1;
    for (int i = 1 ; i <= target ; ++i) {
	for (const auto& iter : nums) {
	    if (i - iter < 0) continue;
	    dp.at(i) += dp.at(i - iter);
	}
    }
    return dp.at(target);
}
