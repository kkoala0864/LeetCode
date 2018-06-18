#include <Solution.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(Interval& a, Interval& b) {
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval>& intervals) {
    vector<Interval> ret;
    if (intervals.empty()) return ret;

    sort(intervals.begin(), intervals.end(), cmp);
    ret.emplace_back(intervals.at(0));
    for (int i = 1 ; i < intervals.size() ; ++i) {
	if (ret.back().end >= intervals.at(i).start) {
	    ret.back().end = max(ret.back().end, intervals.at(i).end);
	} else {
	    ret.emplace_back(intervals.at(i));
	}
    }
    return ret;
}
