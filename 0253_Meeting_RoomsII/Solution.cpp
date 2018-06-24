#include <Solution.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

int Solution::minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> rooms;
    int size = intervals.size();
    for (int i = 0 ; i < size ; ++i) {
	int j(0);
	for (; j < rooms.size() ; ++j) {
	    if (rooms.at(j).end <= intervals.at(i).start) {
		rooms.at(j).end = max(rooms.at(j).end, intervals.at(i).end);
		break;
	    }
	}
	if (j == rooms.size())
	    rooms.emplace_back(intervals.at(i));
    }
    return rooms.size();
}
