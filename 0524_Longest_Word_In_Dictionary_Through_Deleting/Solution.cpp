#include <Solution.h>
#include <iostream>

using namespace std;

string Solution::findLongestWord(string s, vector<string>& d) {
    if (d.empty() || s.empty()) return string("");

    int gSize = s.size();
    string retStr("");
    for (const auto& cmpStr : d) {
	int cIdx(0);
	int gIdx(0);
	while (cIdx < cmpStr.size() && gIdx < gSize) {
	    if (s.at(gIdx) == cmpStr.at(cIdx)) {
		++cIdx;
		if (cIdx == cmpStr.size())
		    break;
	    }
	    ++gIdx;
	}
	if (cIdx == cmpStr.size()) {
	    if (cmpStr.size() > retStr.size()) {
		retStr = move(cmpStr);
	    } else if (cmpStr.size() == retStr.size()) {
		if (cmpStr < retStr) {
		    retStr = cmpStr;
		}
	    }
	}
    }
    return retStr;
}
