#include <Solution.h>
#include <iostream>

using namespace std;


vector<int> Solution::searchRange(vector<int>& nums, int target) {
    vector<int> ret = {-1, -1};
    if (nums.empty())  return ret;
    int start(0);
    int end(nums.size()-1);
    int mid(0);
    while (end > start) {
	mid = (end + start) / 2;
	cout << mid << " : " << nums.at(mid) << endl;
	if (nums.at(mid) > target) {
	    end = mid - 1;
	} else if (nums.at(mid) < target) {
	    start = mid + 1;
	} else {
	    break;
	}
    }
    if (end <= start) return ret;
    start = mid;
    end = mid;
    while (start >= 0 && nums.at(start) == target) {
	--start;
    }
    ret.at(0) = start+1;
    while (end < nums.size() && nums.at(end) == target) {
	++end;
    }
    ret.at(1) = end-1;
    return ret;
}
