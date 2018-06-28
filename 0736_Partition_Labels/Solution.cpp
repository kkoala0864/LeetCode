#include <Solution.h>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> Solution::partitionLabels(string S) {
    vector<int> ret;
    if (S.empty()) return ret;
    int size = S.size();
    vector<int> LastLoc(26, -1);
    for (int i = 0 ; i < size ; ++i) {
	LastLoc.at(S.at(i) - 'a') = i;
    }
    int end(-1);
    int start(0);
    while (end < size-1) {
	start = end + 1;
	end = LastLoc.at(S.at(start) - 'a');
	for (int iter = start; iter <= end ; ++iter) {
	    end = max(end, LastLoc.at(S.at(iter) - 'a'));
	}
	ret.emplace_back(end - start + 1);
    }
    return ret;
}
