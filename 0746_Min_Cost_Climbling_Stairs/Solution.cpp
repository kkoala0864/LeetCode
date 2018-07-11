#include <Solution.h>
#include <iostream>

using namespace std;

// dp.at(i) : min cost from i to top
int Solution::minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();
    vector<int> dp(size+1, 0);

    dp.at(size-1) = 0;
    dp.at(size-2) = 0;
    for (int i = size - 3 ; i >= 0 ; --i) {
	dp.at(i) = min(cost.at(i+1) + dp.at(i+1), cost.at(i+2) + dp.at(i+2));
    }
    return min(cost.at(0) + dp.at(0), cost.at(1) + dp.at(1));
}
