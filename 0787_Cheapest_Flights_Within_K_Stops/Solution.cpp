#include <Solution.h>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int Solution::findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    if (n == 0) return -1;
    if (src == dst) return 0;

    vector<int> Cost(n, 0x1000);
    Cost.at(src) = 0;

    for (int i = 0 ; i <= K ; ++i) {
	vector<int> LocalCost(Cost);
	for (const auto& idx : flights) {
	    if (LocalCost.at(idx.at(1)) > Cost.at(idx.at(0)) + idx.at(2)) {
	        LocalCost.at(idx.at(1)) = Cost.at(idx.at(0)) + idx.at(2);
	    }
	}
	Cost = LocalCost;
    }

    if (Cost.at(dst) == 0x1000)
	return -1;
    else
	return Cost.at(dst);
}
