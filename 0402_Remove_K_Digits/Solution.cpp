#include <Solution.h>
#include <iostream>
#include <stack>
using namespace std;


string Solution::removeKdigits(string num, int k) {
    if (0 == k) return num;
    if (num.empty()) return string("0");
    if (k == num.size()) return string("0");

    stack<char> st;
    int delCnt = 0;
    int sIdx(0);
    while (delCnt < k && sIdx < num.size()) {
	while (!st.empty() && (st.top() > num.at(sIdx)) && delCnt < k) {
	    st.pop();
	    ++delCnt;
	}
	st.emplace(num.at(sIdx));
	++sIdx;
    }
    string ret("");
    int popCnt = k - delCnt;
    while (!st.empty()) {
	if (popCnt-- <= 0) {
	    ret = st.top() + ret;
	}
	st.pop();
    }
    if (sIdx < num.size()) {
	ret += num.substr(sIdx);
    }
    sIdx = 0;
    while (sIdx < ret.size()) {
	if (ret.at(sIdx) != '0')
	    break;
	++sIdx;
    }
    ret = ret.substr(sIdx);
    if (ret.empty()) return string("0");
    return ret;
}

