#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;
using std::max;

vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int start = newInterval[0];
	int end = newInterval[1];
	int size = intervals.size();
	vector<vector<int>> ret;

	for (int i = 0 ; i < size ; ++i) {
		if ((intervals[i][1] < start) || (intervals[i][0] > end)){
			if (intervals[i][0] < start) {
				ret.emplace_back(intervals[i]);
			} else {
				vector<int> tmp = {start, end};
				ret.emplace_back(tmp);
				start = intervals[i][0];
				end = intervals[i][1];
			}
		} else if ((intervals[i][1] >= start) || (intervals[i][0] <= end)) {
			start = min(intervals[i][0], start);
			end = max(intervals[i][1], end);
		}
	}
	newInterval[0] = start;
	newInterval[1] = end;
	ret.emplace_back(newInterval);
	return ret;
}
