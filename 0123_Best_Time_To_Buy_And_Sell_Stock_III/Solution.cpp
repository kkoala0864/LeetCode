#include <Solution.h>
#include <iostream>
#include <iterator>

using namespace std;

int Solution::maxProfit(vector<int>& prices) {
    if (2 > prices.size())
	return 0;
    vector<int> S1, S2, S3, End;
    S1.push_back(-prices[0]);
    S2.push_back(0);
    S3.push_back(-prices[0]);
    End.push_back(0);

    int EndTmp(0);
    for ( int idex = 1 ; idex < prices.size() ; ++idex ) {
	S1.push_back(max(S1[idex-1], -prices[idex]));
	S2.push_back(max(S1[idex-1]+prices[idex], S2[idex-1]));
	S3.push_back(max(S2[idex-1]-prices[idex], S3[idex-1]));
	EndTmp = max(S1[idex-1]+prices[idex], S3[idex-1]+prices[idex]);
	End.push_back(max(EndTmp, End[idex-1]));
    }
    return max(S2[prices.size()-1], End[prices.size()-1]);
}

int Solution::maxProfit_greedy(vector<int>& prices) {
    if (2 > prices.size())
	return 0;

    int minValue(prices[0]), MaxProfit(0);
    vector<int> leftMaxProfit(prices.size(),0);

    for ( size_t i = 1 ; i < prices.size() ; ++i ) {
	if (prices[i] < minValue)
	    minValue = prices[i];
	else
	    MaxProfit = max(MaxProfit, prices[i] - minValue);
	leftMaxProfit[i] = MaxProfit;
    }

    int maxValue(prices[prices.size()-1]), rightMaxProfit(0), ret(leftMaxProfit[prices.size()-1]);
    for ( size_t i = prices.size()-1 ; i--> 0 ;) {
	if (prices[i] > maxValue)
	    maxValue = prices[i];
	else
	    rightMaxProfit = max(rightMaxProfit, maxValue - prices[i]);

	ret = max(ret, rightMaxProfit + leftMaxProfit[i]);
    }
    return ret;
}

