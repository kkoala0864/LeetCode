#include <Solution.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b) {
    return a+b > b+a;
}

string Solution::largestNumber(vector<int>& nums) {
    vector<string> vStr;
    for (const auto& idx : nums) {
	vStr.emplace_back(to_string(idx));
    }
    sort(vStr.begin(), vStr.end(), cmp);
    if (vStr.at(0).at(0) == '0')
	return "0";
    string ret;
    for (const auto& idx : vStr) {
	ret += idx;
    }
    return ret;
}
