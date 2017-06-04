#include <Solution.h>
#include <iostream>
#include <iterator>

using namespace std;

int Solution::maxProfit(vector<int>& prices) {
    if (2 > prices.size())
	return 0;

    vector<int> S1, S2;
    S1.push_back(-prices[0]);
    S2.push_back(0);

    for(size_t i = 1 ; i < prices.size() ; ++i) {
	S1.push_back(max(S1[i-1], -prices[i]));
	S2.push_back(max(S2[i-1], S1[i-1] + prices[i]));
    }

    return max(S1[prices.size() - 1], S2[prices.size() - 1]);
}

/* Greedy algrithm */
int Solution::maxProfit_greedy(vector<int>& prices) {
    if (2 > prices.size())
	return 0;

    int minValue(prices[0]), maxProfit(0);

    for ( int i = 1 ; i < prices.size() ; ++i ) {
	if (prices[i] < minValue)
	    minValue = prices[i];
	if (prices[i] - minValue > maxProfit)
	    maxProfit = prices[i] - minValue;
    }
    return maxProfit;
}

