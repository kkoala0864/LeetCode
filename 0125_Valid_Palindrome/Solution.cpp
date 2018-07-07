#include <Solution.h>
#include <iostream>

using namespace std;

bool Solution::isPalindrome(string s) {
    string tmp;
    for (const auto& idx : s) {
	if (isalnum(idx)) {
	    tmp.push_back(tolower(idx));
	}
    }
    s = move(tmp);

    if (s.size() < 2) return true;
    int begin(0);
    int end(s.size()-1);
    while (end >= begin) {
	if (s.at(begin) == s.at(end)) {
	    ++begin;
	    --end;
	} else {
	    return false;
	}
    }
    return true;
}
