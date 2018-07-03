#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;

void checkPalindrome(const string& s, int left, int right, int& cnt) {
    while (left >=0 && right < s.size()) {
	if (s.at(left) != s.at(right))
	    return;
	else {
	    ++cnt;
	}
	--left;
	++right;
    }
}

int Solution::countSubstrings(string s) {
    int cnt(0);
    for (int i = 0 ; i < s.size() ; ++i) {
	checkPalindrome(s, i, i, cnt);
	checkPalindrome(s, i, i+1, cnt);
    }
    return cnt;
}
