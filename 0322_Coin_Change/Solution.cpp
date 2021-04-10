#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::greater;
using std::min;
using std::cout;
using std::endl;
// recursive to get min combination number, but may meet timeout
// maybe we can get better performance by dp

// recursive
int getMinNumber(int total, const vector<int>& coins, int coinIdx) {
	if (coinIdx >= coins.size() && total > 0) return INT_MAX;
	if (total == 0) return 0;
	int div = total / coins.at(coinIdx);
	int ret = INT_MAX;
	for (int i = div ; i >= 0 ; --i) {
		int minNumber = getMinNumber(total - (i * coins.at(coinIdx)), coins, coinIdx + 1);
		if (minNumber != INT_MAX)
			return min(ret, minNumber + i);
	}
	return ret;
}

int Solution::coinChangeRecur(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end(), greater<int>());
	int ret = getMinNumber(amount, coins, 0);
	return ret == INT_MAX ? -1 : ret;
}

int Solution::coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, INT_MAX);
	int size = coins.size();
	dp.at(0) = 0;
	for (int i = 1 ; i <= amount ; ++i) {
		for (int j = 0 ; j < size ; ++j) {
			if (i - coins.at(j) >= 0) {
				if (dp.at(i - coins.at(j)) != INT_MAX)
					dp.at(i) = min(dp.at(i), dp.at(i - coins.at(j)) + 1);
			}
		}
	}
	return dp.at(amount) == INT_MAX ? -1 : dp.at(amount);
}
