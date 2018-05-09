#include <Solution.h>
#include <iostream>
#include <utility>

using namespace std;

int getCnt(const string& s, const string& t, const int& sIdx, const int& tIdx) {

	if (tIdx == t.size()) {
		return 1;
	}

	bool isFind(false);
	int sepCnt(0);
	for (int idx = sIdx ; idx < s.size() ; ++idx) {
		int depCnt(1);
		if (s.at(idx) == t.at(tIdx)) {
			isFind = true;
			depCnt *= getCnt(s, t, idx+1, tIdx+1);
			if (depCnt > 0) {
				sepCnt += depCnt;
			}
		}
	}

	if (!isFind) {
		return 0;
	} else {
		return sepCnt;
	}
}

int getCntDP(string s, string t) {
	int s_size = s.size();
	int t_size = t.size();

	int arr[t_size+1][s_size+1] = { 0x0 };

	for (int i = 0 ; i <= s_size ; ++i) {
		arr[0][i] = 1;
	}

	for (int i = 1 ; i <= t_size ; ++i) {
		for (int j = 1 ; j <= s_size ; ++j) {
			if (s.at(j-1) == t.at(i-1)) {
				arr[i][j] = arr[i][j-1] + arr[i-1][j-1];
			} else {
				arr[i][j] = arr[i][j-1];
			}
		}
	}
	return arr[t_size][s_size];
}

int Solution::numDistinct(string s, string t) {
	if (s.empty() || t.empty()) {
		return 0;
	}

	return getCntDP(s, t);
}
