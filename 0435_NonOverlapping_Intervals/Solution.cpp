#include <Solution.h>
#include <iostream>

using namespace std;

// find most concatenated interval number and diff by total size
int Solution::eraseOverlapIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    auto cmp = [] (const Interval& lhs, const Interval& rhs) { return lhs.start < rhs.start; };
    sort(intervals.begin(), intervals.end(), cmp);

    int abandonCnt(0);
    for (int i = 1 , pre = 0; i < intervals.size() ; ++i) {
	if (intervals.at(i).start < intervals.at(pre).end) {
	    ++abandonCnt;
	    if (intervals.at(i).end < intervals.at(pre).end) pre = i;
	} else
	    pre = i;
    }

    return abandonCnt;
}

