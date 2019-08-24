#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::pair;
using std::make_pair;
using std::unordered_map;
using std::max;

#if 0
bool recurHelpFunc(const vector<string>& strs, const vector<pair<int, int>>& cnts,
	unordered_map<string, int>& distinct, int m, int n, string propagate, int& TotalCnt, int index) {

    if (0 == m && 0 == n) {
	if (distinct.find(propagate) == distinct.end()) {
	    ++TotalCnt;
	    distinct.emplace(propagate, 1);
	}
	return true;
    }

    if (0 > m || 0 > n) return false;

    int size = strs.size();
    for (int i = index % size; i != ((index - 1) % size); i = (i + 1) % size) {
	if (recurHelpFunc(strs, cnts, distinct, m - cnts.at(i).first,
			n - cnts.at(i).second, propagate + strs.at(i),
			                    TotalCnt, i+1)) return true;
    }
    return false;
}

int Solution::findMaxForm(vector<string>& strs, int m, int n) {
    int cnt(0);
    vector<pair<int, int>> cnts;
    unordered_map<string, int> distinct;
    int size = strs.size();
    for (const auto& str : strs) {
	int One(0), Zero(0);
	for (const auto& iter : str) {
	    if (iter == '1') ++One;
	    else ++Zero;
	}
	cnts.emplace_back(make_pair(Zero, One));
    }

    for (int i = 0 ; i < size ; ++i) {
	string propagate(strs.at(i));
	recurHelpFunc(strs, cnts, distinct,  m - cnts.at(i).first, n - cnts.at(i).second, propagate, cnt, i+1);
    }
    return cnt;
}
#endif

#if 1
int Solution::findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (const auto& str : strs) {
	int zero(0), one(0);
	for (const auto cha : str) (cha == '0') ? ++zero : ++one;
	for (int i = m ; i >= zero ; --i) {
	    for (int j = n ; j >= one ; --j) {
		dp[i][j] = max(dp[i][j], dp[i-zero][j-one] + 1);
	    }
	}
    }
    return dp[m][n];
}
#endif
