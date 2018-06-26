#include <Solution.h>
#include <iostream>
using namespace std;

int Solution::findMinArrowShots(vector<pair<int, int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [] (const pair<int,int>& a, const pair<int, int>& b) -> bool {
					   return a.first < b.first;
					}
					);
    pair<int, int> cur = points.at(0);
    int cnt(1);
    for (int i = 1 ; i < points.size() ; ++i) {
	if (cur.second >= points.at(i).first) {
	    cur.first = points.at(i).first;
	    cur.second = min(cur.second, points.at(i).second);
	} else {
	    cur = move(points.at(i));
	    ++cnt;
	}
    }

    return cnt;
}
