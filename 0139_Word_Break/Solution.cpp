#include <Solution.h>
#include <iostream>
#include <unordered_set>
using namespace std;

bool Solution::wordBreak(string s, vector<string>& wordDict) {
    if (wordDict.size() == 0) return false;
    int size = s.size();
    unordered_set<string> hs;
    for (const auto& word : wordDict) hs.emplace(word);

    vector<bool> dp(size + 1, false);
    dp.at(0) = true;
    for (int i = 1 ; i <= size ; ++i) {
	for (int j = i-1 ; j >= 0 ; --j) {
	    if (dp.at(j) && hs.find(s.substr(j, i-j)) != hs.end()) {
		dp.at(i) = true;
	    }
	}
    }
    return dp.at(size);
}
