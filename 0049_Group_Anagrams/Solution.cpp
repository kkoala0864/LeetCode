#include <Solution.h>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    vector<vector<string>> ret;
    if (strs.empty()) return ret;
    unordered_map<int, vector<string>> count;

    for (const auto& idx: strs) {
	int sCnt(0);
	for (const auto& strIdx : idx) {
	    sCnt += prime.at(strIdx - 'a');
	}
	count[sCnt].emplace_back(idx);
    }

    for (const auto& idx : count) {
	ret.emplace_back(idx.second);
    }
    return ret;
}
