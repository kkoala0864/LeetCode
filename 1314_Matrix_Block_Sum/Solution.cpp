#include <Solution.h>
#include <iostream>

int CalHorMat(vector<vector<int>>& mat, int i, int j, int m, int n, int k) {
	if (i < 0 || i >= m) return 0;
	int ret(0);
	for (int y = j - k ; y <= (j+k) && y < n ; ++y) {
		if (y < 0) continue;
		ret += mat.at(i).at(y);
	}
	return ret;
}

int CalVerMat(vector<vector<int>>&mat, int i, int j, int m, int n, int k) {
	if (j < 0 || j >= n) return 0;
	int ret(0);
	for (int x = i - k ; x <= (i+k) && x < m ; ++x) {
		if (x < 0) continue;
		ret += mat.at(x).at(j);
	}
	return ret;
}

vector<vector<int>> Solution::matrixBlockSum(vector<vector<int>>& mat, int K) {
	int m = mat.size();
	int n = mat.at(0).size();
	vector<vector<int>> ret(m, vector<int>(n, 0));
	vector<vector<int>> diff(m, vector<int>(n, 0));
	int tmp(0);
	for (int i = 0 ; i <= K && i < m; ++i) {
		for (int j = 0 ; j <= K && j < n; ++j) {
			tmp += mat.at(i).at(j);
		}
	}
	ret.at(0).at(0) = tmp;
	for (int j = 1 ; j < n ; ++j) {
		ret.at(0).at(j) = ret.at(0).at(j-1) + CalVerMat(mat, 0, j + K, m, n, K) - CalVerMat(mat, 0, j - K - 1, m, n, K);
	}
	for (int i = 1; i < m ; ++i) {
		ret.at(i).at(0) = ret.at(i-1).at(0) + CalHorMat(mat, i + K, 0, m, n, K) - CalHorMat(mat, i - K - 1, 0, m, n , K);
	}
	for (int i = 1 ; i < m ; ++i) {
		for (int j = 1 ; j < n ; ++j) {
			ret.at(i).at(j) = ret.at(i).at(j-1) + CalVerMat(mat, i, j + K, m, n, K) - CalVerMat(mat, i, j - K - 1, m, n, K);
		}
	}
	return ret;
}
