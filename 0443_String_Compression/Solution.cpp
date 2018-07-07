#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::compress(vector<char>& chars) {
    int copyIdx(1);
    int cnt(1);
    for (int i = 1 ; i < chars.size() ; ++i) {
	if (chars.at(i) == chars.at(i-1)) {
	    ++cnt;
	} else {
	    if (cnt > 1) {
		string cntStr = to_string(cnt);
		for (int idx = 0 ; idx < cntStr.size() ; ++idx) {
		    chars.at(copyIdx++) = cntStr.at(idx);
		}
	    }
	    cnt = 1;
	    chars.at(copyIdx++) = chars.at(i);
	}
    }
    if (cnt > 1) {
	string cntStr = to_string(cnt);
	for (int idx = 0 ; idx < cntStr.size() ; ++idx) {
	    chars.at(copyIdx++) = cntStr.at(idx);
	}
    }
    return copyIdx;
}
