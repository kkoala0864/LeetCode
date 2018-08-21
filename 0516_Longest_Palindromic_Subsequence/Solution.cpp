#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;
// bbbab   =>    bbbb
// cbbd    =>    bb

int checkPalindromic(const string& s, int start, int end, int curLen) {
    if (start < 0 || end >= s.size()) return curLen;
    if (s.at(start) == s.at(end)) {
	return checkPalindromic(s, start - 1, end + 1, curLen + 2);
    } else {
	int left = start;
	int leftLen(curLen);
	for (; left >= 0 ; --left) {
	    if (s.at(left) == s.at(end)) break;
	}
	if (left >= 0) {
	    leftLen = checkPalindromic(s, left - 1, end + 1, curLen + 2);
	}
	int right = end;
	int rightLen(curLen);
	for (; right < s.size() ; ++right) {
	    if (s.at(right) == s.at(start)) break;
	}
	if (right < s.size()) {
	    rightLen = checkPalindromic(s, start - 1, right + 1, curLen + 2);
	}
	return max(leftLen, rightLen);
    }
}

int Solution::longestPalindromeSubseq(string s) {
    if (s.empty()) return 0;
    int size = s.size();
    int maxVal(0);
    for (int i = 0 ; i < size ; ++i) {
	maxVal = max(checkPalindromic(s, i-1, i+1, 1), maxVal);
	maxVal = max(checkPalindromic(s, i, i+1, 0), maxVal);
    }
    return maxVal;
}

// dp[i][j] : max Len of subsequence start from i end with j
int Solution::longestPalindromeSubseq2(string s) {
    if (s.empty()) return 0;
    int size = s.size();
    vector<int> dp(size, 0);
    int lastOne(0);
    for (int j = 0 ; j < size ; ++j) {
	for (int i = j ; i >= 0 ; --i) {
	    int tmp = dp.at(i);
	    if (i == j) {
		dp.at(i) = 1;
	    } else {
		if (s.at(i) == s.at(j)) {
		    dp.at(i) = lastOne + 2;
		} else {
		    dp.at(i) = max(dp.at(i+1), dp.at(i));
		}
	    }
	    lastOne = tmp;
	}
    }
    return dp.at(0);
}
