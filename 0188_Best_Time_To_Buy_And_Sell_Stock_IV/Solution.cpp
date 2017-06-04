#include <Solution.h>
#include <iostream>
#include <iterator>
#include <utility>

using namespace std;


/* p[i][j] = Max Profit before j day at most i transactions;
 * p[i][j] = max( p[i][j-1], prices[j] - prices[k] + p[i-1][k] ) which k in {0 ~ j-1}
 *         = max( p[i][j-1], prices[j] + max(p[i-1][k] - prices[k])
 * p[i][0] = 0
 * p[0][j] = 0
 * */
int Solution::maxProfit(int k, vector<int>& prices) {
    int pSize = prices.size();
    if (2 > pSize)
	return 0;

    // if k > pSize/2 means the most trasaction times overs the number of days can do transaction
    // so, it equal to unlimit transaction.
    if (k > pSize/2) {
	int maxProfit(0);
	for (size_t idex = 1 ; idex < pSize ; ++idex) {
	    maxProfit += (0 < prices[idex] - prices[idex-1]) ? prices[idex] - prices[idex-1] : 0;
	}
	return maxProfit;
    }

    vector<vector<int> > Profit(k+1, vector<int>(pSize,0)); // p[k+1][pSize]
    for (size_t tCnt = 1 ; k >= tCnt ; ++tCnt) {
	int tmpMax = Profit[tCnt-1][0] - prices[0];
	for (size_t dCnt = 1 ; pSize > dCnt ; ++dCnt) {
	    Profit[tCnt][dCnt] = max(Profit[tCnt][dCnt-1], prices[dCnt] + tmpMax);
	    tmpMax = max(tmpMax, Profit[tCnt-1][dCnt] - prices[dCnt]);
	}
    }

    return Profit[k][pSize-1];
}
