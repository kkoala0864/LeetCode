#include <Solution.h>
#include <iostream>
using std::min;
/*
int Solution::countSquares(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix.at(0).size();
	vector<vector<int>> maxSqaure(m, vector<int>(n, 0));
	int cnt(0);

	int squareSize = m > n ? n : m;

	for (int i = 0 ; i < squareSize ; ++i) {
		for (int x = 0 ; (x + i) < m ; ++x) {
			for (int y = 0 ; (y + i) < n ; ++y) {
				if (maxSqaure.at(x).at(y) != i) continue;
				bool fail(false);
				for (int offset = 0 ; offset <= i ; ++offset) {
					if (matrix.at(x + offset).at(y + i) == 0) {
						fail = true;
						break;
					}
					if (matrix.at(x + i).at(y + offset) == 0) {
						fail = true;
						break;
					}
				}
				if (!fail) {
					++maxSqaure.at(x).at(y);
					++cnt;
				}
			}
		}
	}
	return cnt;
}
*/

int Solution::countSquares(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix.at(0).size();

	vector<vector<int>> dp(m, vector<int>(n, 0));
	int ret(0);
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			dp.at(i).at(j) = matrix.at(i).at(j);
			if (i > 0 && j > 0 && matrix.at(i).at(j) > 0) {
				dp.at(i).at(j) = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
			}
			ret += dp.at(i).at(j);
		}
	}
	return ret;
}
