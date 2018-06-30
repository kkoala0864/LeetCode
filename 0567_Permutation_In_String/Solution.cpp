#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;

bool checkVec(const vector<int>& charCnt) {
    for (const auto& idx : charCnt) {
	if (idx != 0)
	    return false;
    }
    return true;
}

bool Solution::checkInclusion(string s1, string s2) {
    int s1Size = s1.size();
    int s2Size = s2.size();
    if (s1Size > s2Size) return false;
    vector<int> charCnt(26, 0);
    for (const auto& idx : s1)
	++charCnt.at(idx-'a');

    for (int i = 0 ; i < s1Size-1 ; ++i) {
	--charCnt.at(s2.at(i)-'a');
    }
    for (int i = s1Size-1 ; i < s2.size() ; ++i) {
	--charCnt.at(s2.at(i) - 'a');
	if (checkVec(charCnt)) return true;
	else ++charCnt.at(s2.at(i-s1Size+1) - 'a');
    }
    return false;
}
