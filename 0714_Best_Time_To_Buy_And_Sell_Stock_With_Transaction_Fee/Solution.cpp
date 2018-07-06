#include <Solution.h>
#include <iostream>

using namespace std;

int maxProfitRecur(vector<int>& prices, int fee, int start) {
    int size = prices.size();
    int maxProfit(0);
    for (int i = start ; i < size ; ++i) {
	for (int j = i + 1 ; j < size ; ++j) {
	    if (j == (size-1) || prices.at(j) > prices.at(j+1)) {
		if (prices.at(j) - prices.at(i) > fee) {
		    int cost = prices.at(j) - prices.at(i) - fee;
		    if (j+1 < size) {
			cost += maxProfitRecur(prices, fee, j+1);
		    }
		    maxProfit = max(maxProfit, cost);
		}
	    }
	}
    }
    return maxProfit;
}

int Solution::maxProfit(vector<int>& prices, int fee) {
    return maxProfitRecur(prices, fee, 0);
}

// DP
// hold[i] max profit if hold stock at day i
// sold[i] max profit if no stock at day i
//
//
// hold[i] = max(hold[i-1], sold[i-1] - prices[i]);
// sold[i] = max(sold[i-1], hold[i-1] + prices[i] - fee);
int Solution::maxProfit2(vector<int>& prices, int fee) {
    int size = prices.size();
    if (size < 2) return 0;

    //vector<int> hold(size, 0);
    //vector<int> sold(size, 0);
    //hold.at(0) = 0 - prices.at(0);
    //sold.at(0) = 0;
    int hold = 0 - prices.at(0);
    int sold = 0;

    for (int i = 1 ; i < size ; ++i) {
	//hold.at(i) = max(hold.at(i-1), sold.at(i-1) - prices.at(i));
	//sold.at(i) = max(sold.at(i-1), hold.at(i-1) + prices.at(i) - fee);
	int tmp = hold;
	hold = max(hold, sold - prices.at(i));
	sold = max(sold, tmp + prices.at(i) - fee);
    }
    //return sold.at(size-1);
    return sold;
}

//Greedy
//
//buy in :
// if (prices[i] - low > fee)
// high = prices[i]
//
//sale out :
// if (high - prices[i] > fee)
// low = 0;
// high = 0;
//
//update highest - only if highest is set;
//update lowest - every day

int Solution::maxProfit3(vector<int>& prices, int fee) {
    int MaxProfit(0);
    int *low = nullptr, *high = nullptr;
    for (int i = 0 ; i < prices.size() ; ++i) {
	if (low && !high && prices[i] - *low > fee) high = &prices[i]; // buy in
	if (high && prices[i] > *high) high = &prices[i]; // update highest
	if (high && ((*high - prices[i] > fee) || (i == prices.size() - 1))) { // sale out
	    MaxProfit += *high - *low - fee;
	    low = nullptr;
	    high = nullptr;
	}
	if (!low || (prices[i] < *low)) low = &prices[i]; //update lowest
    }
    return MaxProfit;
}

