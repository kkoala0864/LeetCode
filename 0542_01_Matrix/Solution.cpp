#include <Solution.h>
#include <iostream>
#include <utility>
#include <queue>
using std::pair;
using std::queue;
using std::make_pair;
using std::cout;
using std::endl;
using std::min;

vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
	return vector<vector<int>>();
    }

    int xSize = matrix.size();
    int ySize = matrix.at(0).size();
    vector<pair<int, int>> direction = {{1, 0},{-1, 0},{0, 1},{0, -1}};
    vector<vector<int>> retM(xSize, vector<int>(ySize, -1));
    queue<pair<int, int>> nonZero;
    for (int x = 0 ; x < xSize ; ++x) {
	for (int y = 0 ; y < ySize ; ++y) {
	    if (matrix.at(x).at(y) == 0) {
		retM.at(x).at(y) = 0;
	    }
	    if (matrix.at(x).at(y) > 0) {
		nonZero.push(make_pair(x,y));
	    }
	}
    }

    while (!nonZero.empty()) {
	queue<pair<int, int>> bfs;
	bfs.push(make_pair(nonZero.front().first, nonZero.front().second));
	nonZero.pop();
	int cur_dis(0);
	int cur_lv(1);
	int next_lv(0);
	int curX = bfs.front().first;
	int curY = bfs.front().second;
	while (!bfs.empty()) {
	    int x = bfs.front().first;
	    int y = bfs.front().second;
	    bfs.pop();
	    --cur_lv;
	    for (const auto& idx : direction) {
		int nextX = x + idx.first;
		int nextY = y + idx.second;
		if (nextX >= 0 && nextX < xSize && nextY >= 0 && nextY < ySize) {
		    if (retM.at(nextX).at(nextY) == 0) {
			retM.at(curX).at(curY) = cur_dis + 1;
		    } else {
			bfs.push(make_pair(nextX, nextY));
			++next_lv;
		    }
		}
	    }
	    if (retM.at(curX).at(curY) > 0) {
		break;
	    }
	    if (0 == cur_lv) {
		++cur_dis;
		cur_lv = next_lv;
		next_lv = 0;
	    }
	}
    }
    return retM;
}

vector<vector<int>> Solution::updateMatrix2(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX- 1000));
    int i,j;
    for(i=0;i<m;i++){
	for(j=0;j<n;j++){
	    if(matrix[i][j] == 0)
		dp[i][j] = 0;
	    else{
		if(i>0)
		    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);

		if(j>0)
		    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
	    }
	}
    }

    for(i=m-1;i>=0;i--)
	for(j=n-1;j>=0;j--){
	    if(i < (m-1))
		dp[i][j] = min(dp[i][j], dp[i+1][j]+1);

	    if(j < (n-1))
		dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
	}

    return dp;
}
