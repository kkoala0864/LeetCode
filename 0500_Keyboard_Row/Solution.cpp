#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> Solution::findWords(vector<string>& words) {
    vector<string> ret;
    unordered_map<int,int> hash_table;

    string one("qwertyuiop");
    string two("asdfghjkl");
    string three("zxcvbnm");
    for ( const auto& oneIdx : one )
	hash_table[static_cast<int>(oneIdx)] = 1;
    for ( const auto& twoIdx : two )
	hash_table[static_cast<int>(twoIdx)] = 2;
    for ( const auto& threeIdx : three )
	hash_table[static_cast<int>(threeIdx)] = 3;

    for (size_t wIdx=0 ; wIdx < words.size() ; ++wIdx) {
	int change(0);
	string compString = words[wIdx];
        transform(words[wIdx].begin(), words[wIdx].end(), compString.begin(), ::tolower);
        int curStat = hash_table[static_cast<int>(compString.at(0))];

        for (size_t sIdx=1 ; sIdx < compString.size() ; ++sIdx) {
            if (curStat != hash_table[static_cast<int>(compString.at(sIdx))]) {
		change = 1;
		break;
            }
        }
	if (0 == change)
	    ret.push_back(words[wIdx]);
    }
    return ret;
}
