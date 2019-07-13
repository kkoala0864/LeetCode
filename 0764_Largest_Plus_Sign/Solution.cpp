#include <Solution.h>
#include <iostream>

using std::max;
using std::min;
using std::cout;
using std::endl;

int check(const vector<vector<int>>& matrix, int x, int y, int MaxOrder, int N) {
    int order = 1;
    for (int step = 1; step < MaxOrder ; ++step) {
	if ((x + step) < N && (x - step) >= 0 && (y + step) < N && (y - step) >= 0) {
	    if (matrix.at(x+step).at(y) != 0 &&
		matrix.at(x-step).at(y) != 0 &&
		matrix.at(x).at(y+step) != 0 &&
		matrix.at(x).at(y-step) != 0) {
		++order;
	    } else {
		break;
	    }
	} else {
	    break;
	}
    }
    return order;
}

int Solution::orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    vector<vector<int>> matrix(N, vector<int>(N, 1));
    for (const auto& mine : mines) matrix.at(mine.at(0)).at(mine.at(1)) = 0;

    int MaxOrder = (N % 2) == 1 ?  (N / 2) + 1: (N / 2);
    int MaxValue = 0;

    if (mines.empty()) return MaxOrder;
    for (int i = 0 ; i < N ; ++i) {
	for (int j = 0 ; j < N ; ++j) {
	    if (matrix.at(i).at(j) == 1) {
		int ret = check(matrix, i, j, MaxOrder, N);
		MaxValue = max(ret, MaxValue);
	    }
	}
    }
    return MaxValue;
}

int Solution::orderOfLargestPlusSignDP(int N, vector<vector<int>>& mines) {
    vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
    for (const auto& mine : mines) dp.at(mine.at(0)).at(mine.at(1)) = 0;

    for (int i = 0 ; i < N ; ++i) {
	int l = 0, r = 0, u = 0, d = 0;
	for (int j = 0, k = N-1 ; j < N && k >= 0 ; ++j, --k) {
	    dp.at(i).at(j) = min(dp.at(i).at(j), l = dp.at(i).at(j) ? l + 1 : 0);
	    dp.at(j).at(i) = min(dp.at(j).at(i), d = dp.at(j).at(i) ? d + 1 : 0);
	    dp.at(i).at(k) = min(dp.at(i).at(k), r = dp.at(i).at(k) ? r + 1 : 0);
	    dp.at(k).at(i) = min(dp.at(k).at(i), u = dp.at(k).at(i) ? u + 1 : 0);
	}
    }
    int MaxValue = 0;
    for (int i = 0 ; i < N ; ++i) {
	for (int j = 0 ; j < N ; ++j) {
	    MaxValue = max(dp.at(i).at(j), MaxValue);
	}
    }
    return MaxValue;
}
