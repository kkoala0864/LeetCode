#include <Solution.h>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(const pair<int, char>& a, const pair<int, char>& b) {
    return a.first > b.first;
}

string Solution::reorganizeString(string S) {
    if (S.empty()) return S;
    int n = S.size();
    vector<int> Cnt(26);
    for (const auto& idx : S) {
	++Cnt.at(idx-'a');
    }

    vector<pair<int, char>> CharCnt;
    for (int i = 0 ; i < Cnt.size() ; ++i) {
	if (Cnt.at(i) > (n + 1) /2) return string("");
	if (Cnt.at(i) != 0) {
	    CharCnt.emplace_back(Cnt.at(i), i + 'a');
	}
    }
    sort(CharCnt.begin(), CharCnt.end(), cmp);
    string AppendStr;
    string ret;
    for (int i = 0 ; i < CharCnt.size() ; ++i) {
	AppendStr += string(CharCnt.at(i).first, CharCnt.at(i).second);
    }
    for (int i = 0, j = (n-1)/2+1 ; i < (n-1)/2 ; ++i, ++j) {
	ret += AppendStr.at(i);
	if (j < n) ret += AppendStr.at(j);
    }
    return ret;
}

