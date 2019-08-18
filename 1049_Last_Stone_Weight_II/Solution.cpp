#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

// sum - i - i : seperate all into two group as (i) and (sum - i)
//               and "smash" is two group do sub
//               so (sum - i) - i
int Solution::lastStoneWeightII(vector<int>& stones) {
    vector<bool> dp(1501, 0);
    dp.at(0) = 1;

    int sum(0);
    for (auto& stone : stones) {
	sum += stone;
	for (int iter = sum ; iter >= stone ; --iter) {
	    dp.at(iter) = dp.at(iter) | dp.at(iter - stone);
	}
    }

    for (int i = sum / 2 ; i > 0 ; --i) {
	if (dp.at(i)) {
	    return sum - i - i;
	}
    }
    return 0;
}
