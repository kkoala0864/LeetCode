#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;

string checkOdd(const string& s, int idx) {
    int left = idx-1;
    int right = idx+1;
    while (left >= 0 && right < s.size() && s.at(left) == s.at(right)) {
	--left;
	++right;
    }
    return s.substr(left+1, right-left-1);
}

string checkEven(const string& s, int idx) {
    int left = idx;
    int right = idx+1;
    while (left >= 0 && right < s.size() && s.at(left) == s.at(right)) {
	--left;
	++right;
    }
    if ((right-left-1) > 0)
	return s.substr(left+1, right-left-1);
    else
	return string("");
}

string Solution::longestPalindrome(string s) {
    if (s.empty()) return string("");
    if (1 == s.size()) return s;

    string ret("");
    for (int i = 0 ; i < s.size() ; ++i) {
	string oddStr = checkOdd(s, i);
	string evenStr = checkEven(s, i);
	if (oddStr.size() > ret.size())
	    ret = move(oddStr);
	if (evenStr.size() > ret.size())
	    ret = move(evenStr);
    }
    return ret;
}

string Solution::longestPalindromeDP(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int MaxLength(0);
    int maxStart(0);

    for (int len = 1 ; len <= s.size() ; ++len) {
	for (int start = 0 ; (start+len-1) < s.size() ; ++start) {
	    int end = start + len - 1;
	    if (s.at(start) == s.at(end)) {
		if (len > 2)
		    dp.at(start).at(end) = dp.at(start+1).at(end-1) & true;
		else
		    dp.at(start).at(end) = true;
	    }

	    if (dp.at(start).at(end)) {
		if (len > MaxLength) {
		    MaxLength = len;
		    maxStart = start;
		}
	    }
	}
    }
    return s.substr(maxStart, MaxLength);
}
