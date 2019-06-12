#include <Solution.h>
#include <iostream>

using std::min;

int Solution::mincostTickets(vector<int>& days, vector<int>& costs) {
    int size = days.size();
    vector<int> dp(size+1, 0);
    int minSingleCosts = min(costs.at(0), costs.at(1));
    minSingleCosts = min(minSingleCosts, costs.at(2));

    dp.at(1) = costs.at(0);

    for (int i = 2 ; i <= size ; ++i) {
	dp.at(i) = i * costs.at(0);
	for (int j = i - 1; j >= 1 ; --j) {
	    int range = days.at(i-1) - days.at(j-1);
	    int minCost = dp.at(j) + (i-j) * minSingleCosts;
	    if (range < 7) minCost = min(minCost, dp.at(j-1) + costs.at(1));
	    if (range < 30) minCost = min(minCost, dp.at(j-1) + costs.at(2));
	    dp.at(i) = min(dp.at(i), minCost);
	}
    }
    return dp.at(size);
}
