#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;

int Solution::numDecodings(string s) {
    if (s.empty()) return 0;
    if (1 == s.size()) return s.at(0) - '0' ? 0 : 1;
    vector<int> dp(s.size()+1,  0);
    dp.at(0) = 1;
    for (int i = 1 ; i <= s.size(); ++i) {
	dp.at(i) = (s.at(i-1) == '0') ? 0 : dp.at(i-1);
	if (i > 1 && ((s.at(i-2) == '1') || (s.at(i-2) == '2' && s.at(i-1) <= '6'))) {
	    dp.at(i) += dp.at(i-2);
	}
    }

    return dp.at(s.size());
}
