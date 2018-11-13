#include <Solution.h>
#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::max;
using std::min;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
using std::accumulate;

int Solution::minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<pair<int, string>> dp(n+1, make_pair(0, ""));

    for (int i(1) ; i <= m ; ++i) {
	pair<int, string> lastOne(dp.at(0));
	for (int j(1) ; j <= n ; ++j) {
	    pair<int, string> tmp(dp.at(j));
	    if (s1.at(i-1) == s2.at(j-1)) {
		dp.at(j).first = lastOne.first + 1;
		dp.at(j).second = lastOne.second;
		dp.at(j).second.push_back(s1.at(i-1));
	    } else {
		dp.at(j).first = max(tmp.first, dp.at(j-1).first);
		if (tmp.first > dp.at(j-1).first) {
		    dp.at(j).second = tmp.second;
		} else if (tmp.first < dp.at(j-1).first) {
		    dp.at(j).second = dp.at(j-1).second;
		} else {
		    int iTmp(0), jTmp(0);
		    for (const auto& ele : tmp.second) iTmp += ele;
		    for (const auto& ele : dp.at(j-1).second) jTmp += ele;
		    if (iTmp > jTmp)
			dp.at(j).second = tmp.second;
		    else
			dp.at(j).second = dp.at(j-1).second;
		}
	    }
	    lastOne = tmp;
	}
    }

    int total(0);
    for (const auto& ele : s1) total += ele;
    for (const auto& ele : s2) total += ele;
    int LCS(0);
    for (const auto& ele : dp.at(n).second) LCS += ele;
    total -= 2*LCS;
    return total;
}

int Solution::minimumDeleteSumII(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<int> dp(n+1, 0);

    int first = dp.at(0);
    for (int i(0) ; i <= m ; ++i) {
	int lastOne = dp.at(0);
	if (i > 0) {
	    first += s1.at(i-1);
	    dp.at(0) = first;
	}
	for (int j(1) ; j <= n ; ++j) {
	    int tmp = dp.at(j);
	    if (0 == i) {
		dp.at(j) = dp.at(j-1) + s2.at(j-1);
	    } else {
		if (s1.at(i-1) == s2.at(j-1)) {
		    dp.at(j) = lastOne;
		} else {
		    dp.at(j) = min(dp.at(j) + s1.at(i-1), dp.at(j-1) + s2.at(j-1));
		}
	    }
	    lastOne = tmp;
	}
    }
    return dp.at(n);
}

int Solution::minimumDeleteSumIII(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i(1) ; i <= m ; ++i) {
	for (int j(1) ; j <= n ; ++j) {
	    if (s1[i-1] == s2[j-1])
		dp[i][j] = dp[i-1][j-1] + s1[i-1];
	    else
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	}
    }
    int sum = accumulate(s1.begin(), s1.end(), 0);
    sum += accumulate(s2.begin(), s2.end(), 0);
    return sum - 2 * dp[m][n];
}
