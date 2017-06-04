#include <Solution.h>
#include <iostream>
#include <iterator>

using namespace std;

int Solution::maxProfit(vector<int>& prices) {
    if (2 > prices.size())
	return 0;
    vector<int> S0, S1;
    S0.push_back(0);
    S1.push_back(-prices[0]);

    for ( int idex = 1 ; idex < prices.size() ; ++idex ) {
	S0.push_back(max(S0[idex-1], S1[idex-1]+prices[idex]));
	S1.push_back(max(S0[idex-1]-prices[idex], S1[idex-1]));
    }
    return max(S0[prices.size()-1], S1[prices.size()-1]);
}

int Solution::maxProfit_greedy(vector<int>& prices) {
    if (2 > prices.size())
	return 0;

    int maxProfit(0);
    for ( int i = 1 ; i < prices.size() ; ++i ) {
	prices[i] - prices[i-1] > 0 ? maxProfit += (prices[i] - prices[i-1]) : 0;
    }

    return maxProfit;
}
