#include <Solution.h>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int Solution::firstUniqChar(string s) {
    if (s.empty()) return -1;
    vector<pair<int, int>> charCnt(26);

    for (int i = 0 ; i < s.size() ; ++i) {
	if (charCnt.at(s.at(i) - 'a').second == 0) {
	    charCnt.at(s.at(i) - 'a').first = i;
	}
	++charCnt.at(s.at(i) - 'a').second;
    }
    int ret(INT_MAX);
    for (int i = 0 ; i < charCnt.size() ; ++i) {
	if (charCnt.at(i).second == 1) {
	    ret = min(ret, charCnt.at(i).first);
	}
    }

    return ret == INT_MAX ? -1 : ret;
}
