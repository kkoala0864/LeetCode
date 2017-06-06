#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> Solution::findWords(vector<string>& words) {
    vector<string> ret;
    unordered_map<int,int> hash_table;

    hash_table['q']=1;
    hash_table['w']=1;
    hash_table['e']=1;
    hash_table['r']=1;
    hash_table['t']=1;
    hash_table['y']=1;
    hash_table['u']=1;
    hash_table['i']=1;
    hash_table['o']=1;
    hash_table['p']=1;
    hash_table['a']=2;
    hash_table['s']=2;
    hash_table['d']=2;
    hash_table['f']=2;
    hash_table['g']=2;
    hash_table['h']=2;
    hash_table['j']=2;
    hash_table['k']=2;
    hash_table['l']=2;
    hash_table['z']=3;
    hash_table['x']=3;
    hash_table['c']=3;
    hash_table['v']=3;
    hash_table['b']=3;
    hash_table['n']=3;
    hash_table['m']=3;

    for (size_t wIdx=0 ; wIdx < words.size() ; ++wIdx) {
	int change(0);
	string compString = words[wIdx];
        transform(words[wIdx].begin(), words[wIdx].end(), compString.begin(), ::tolower);
        int curStat = hash_table[(int)(compString.at(0))];

        for (size_t sIdx=1 ; sIdx < compString.size() ; ++sIdx) {
            if (curStat != hash_table[(int)(compString.at(sIdx))]) {
		change = 1;
		break;
            }
        }
	if (0 == change)
	    ret.push_back(words[wIdx]);
    }
    return ret;
}
