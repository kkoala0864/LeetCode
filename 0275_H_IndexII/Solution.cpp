#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::hIndex(vector<int>& citations) {
    if (citations.empty()) return 0;
    int ret = 0;
    int size = citations.size();
    int end = size - 1;
    int start = 0;
    while (end >= start) {
	int mid = (end + start)/2;
	if ((size - mid) <= citations.at(mid)) {
	    ret = size - mid;
	    end = mid - 1;
	} else {
	    start = mid + 1;
	}
    }
    return ret;
}
