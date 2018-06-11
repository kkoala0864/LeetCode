#include <Solution.h>
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <unordered_map>
using namespace std;

string Solution::frequencySort(string s) {
    if (s.empty()) return s;
    unordered_map<char,int> count;

    for (const auto& iter : s) {
	++count[iter];
    }

    priority_queue<pair<int, char>> maxHeap;
    for (const auto& iter :  count) {
	if (iter.second > 0) {
	    maxHeap.emplace(make_pair(iter.second, iter.first));
	}
    }
    string::iterator ret = s.begin();
    while (!maxHeap.empty()) {
	int sCnt = maxHeap.top().first;
	while (sCnt-- > 0) {
	    *(ret++) = maxHeap.top().second;
	}
	maxHeap.pop();
    }
    return s;
}



string Solution::frequencySort2(string s) {
    if (s.empty()) return s;
    vector<int> count(26);

    for (const auto& iter : s) {
	++count[iter-'a'];
    }

    priority_queue<charactor> maxHeap;
    for (int i = 0 ; i < 26 ; ++i) {
        if (count.at(i) > 0) {
	    charactor node;
	    node.element = i + 'a';
	    node.counter = count.at(i);
            maxHeap.emplace(node);
        }
    }
    string::iterator ret = s.begin();
    while (!maxHeap.empty()) {
	int sCnt = maxHeap.top().counter;
	while (sCnt-- > 0) {
	    *(ret++) = maxHeap.top().element;
	}
	maxHeap.pop();
    }
    return s;
}

