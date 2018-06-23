#include <Solution.h>
#include <iostream>
#include <unordered_map>

using namespace std;

bool Solution::isSubsequence(string s, string t) {
    unordered_map<char, int> hashTable;
    for (int i = 0 ; i < t.size() ; ++i) {
	hashTable.emplace(t.at(i), i);
    }

    int cnt(INT_MIN);
    for (int i = 0 ; i < s.size() ; ++i) {
	if (hashTable.find(s.at(i)) != hashTable.end() && hashTable.at(s.at(i)) >= cnt) {
	    cnt = hashTable.at(s.at(i));
	} else {
	    return false;
	}
    }
    return true;
}

bool Solution::isSubsequence2(string s, string t) {
    if (s.empty()) return true;
    if (t.empty()) return false;
    int sIdx(0);
    int tIdx(0);
    while (tIdx < t.size() && sIdx < s.size()) {
	if (s.at(sIdx) == t.at(tIdx)) {
	    ++sIdx;
	    if (sIdx == s.size())
		break;
	}
	++tIdx;
    }
    return sIdx == s.size();
}
