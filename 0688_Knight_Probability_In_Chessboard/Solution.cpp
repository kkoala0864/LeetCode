#include <Solution.h>
#include <iostream>
#include <vector>
#include <math.h>

using std::vector;
using std::pair;
using std::cout;
using std::endl;
// Probability of each direction is 0.125
// [1,2][2,1][-1,2][-2,1][1,-2][2,-1][-1,-2][-2,-1]
// [0,0][0,N-1][N-1,0][N-1,N-1]
// if has moved off the chessboard, it would stop moving
// func(N, K, r, c) = 8 * func(N, K-1, r+ , c)
double Solution::knightProbability(int N, int K, int r, int c) {
    vector<pair<int, int>> directions = {{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
    vector<vector<double>> map(N, vector<double>(N));
    map.at(r).at(c) = 1;

    for (int i = 0 ; i < K ; ++i) {
	vector<vector<double>> nextMap(N, vector<double>(N));
	for (int r = 0 ; r < N ; ++r) {
	    for (int c = 0 ; c < N ; ++c) {
		if (map.at(r).at(c) != 0) {
		    double factor = map.at(r).at(c);
		    for (const auto& direct : directions) {
			int nextR = r + direct.first;
			int nextC = c + direct.second;
			if ((nextC >= 0 && nextC < N) && (nextR >= 0 && nextR < N)) {
			    nextMap.at(nextR).at(nextC) += (factor * 0.125);
			}
		    }
		    map.at(r).at(c) = 0;
		}
	    }
	}
	map = move(nextMap);
    }
    double ret = 0;
    for (int r = 0 ; r < N ; ++r) {
	for (int c = 0 ; c < N ; ++c) {
	    ret += map.at(r).at(c);
	}
    }
    return ret;
}
