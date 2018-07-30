#include <Solution.h>
#include <iostream>

using namespace std;
void reverse(vector<int>& ret, int start, int end) {
    while (end >= start) {
	swap(ret.at(end--), ret.at(start++));
    }
}

vector<int> Solution::findPermutation(string s) {
    if (s.empty()) return vector<int>();
    vector<int> ret;
    for (int i = 1 ; i <= s.size()+1 ; ++i)
	ret.emplace_back(i);

    int i = 0;
    while (i < s.size() && s.at(i) == 'D') ++i;

    if (i > 0) { reverse(ret, 0, i); }
    while (i < s.size()) {
	if ('D' == s.at(i)) {
	    int iIdx = i;
	    while (i < s.size() && 'D' == s.at(i)) ++i;
	    reverse(ret, iIdx, i);
	} else
	    ++i;
    }
    return ret;
}
