#include <Solution.h>
#include <iostream>

using namespace std;

bool Solution::exist(vector<vector<char> >& board, string word) {
    m = board.size();
    n = board[0].size();
    if (0 == m*n) {
	return false;
    }
    for ( size_t i = 0 ; i < m ; ++i ) {
	for ( size_t j = 0 ; j < n ; ++j ) {
	    if (check(board, word, i, j))
		return true;
	}
    }
    return false;
}

bool Solution::check(vector<vector<char> >& board, const string& strCmp, size_t i, size_t j) {
    if ( strCmp.empty() || ( i >= m ) || ( j >= n ) || 0 > i || 0 > j || 1 == board[i][j] || board[i][j] != strCmp.at(0) )
	return false;

    if ( 1 == strCmp.size() )
       return true;

    char original = strCmp.at(0);
    board[i][j] = 1;
    if ( check(board, strCmp.substr(1), i+1 , j   ) ||
	 check(board, strCmp.substr(1), i-1 , j   ) ||
	 check(board, strCmp.substr(1), i   , j+1 ) ||
	 check(board, strCmp.substr(1), i   , j-1 ) )
    {
	return true;
    }

    board[i][j] = original;
    return false;

}
