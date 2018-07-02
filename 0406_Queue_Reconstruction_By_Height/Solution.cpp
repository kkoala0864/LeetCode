#include <Solution.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    //if (a.second == b.second) {
    //    return a.first < b.first;
    //} else {
    //    return a.second < b.second;
    //}
    if (a.first == b.first) {
	return a.second < b.second;
    } else {
	return a.first > b.first;
    }
}

vector<pair<int, int>> Solution::reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int, int>> res;
    sort(people.begin(), people.end(), cmp);
    for (int i = 0 ; i < people.size() ; ++i) {
	res.insert(res.begin()+people.at(i).second, people.at(i));
    }
    return res;
}
