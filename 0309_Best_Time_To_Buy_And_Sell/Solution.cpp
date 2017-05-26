#include <Solution.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iterator>

using namespace std;

int Solution::maxProfit(vector<int>& prices) {
    if (prices.size() <= 1)
	return 0;
    vector<int> S0, S1, S2;
    S0.push_back(0);
    S1.push_back(-prices[0]);
    S2.push_back(0);

    for(size_t idex = 1 ; idex < prices.size() ; ++idex) {
	S0.push_back(max(S0[idex - 1], S2[idex - 1]));
	S1.push_back(max(S1[idex - 1], S0[idex - 1] - prices[idex]));
	S2.push_back(S1[idex - 1] + prices[idex]);
    }

    return max(S0[prices.size() - 1] , S2[prices.size() - 1]);
}

