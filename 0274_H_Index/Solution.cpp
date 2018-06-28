#include <Solution.h>
#include <iostream>


using namespace std;

int Solution::hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int size = citations.size();
    int start(0);
    int end(size - 1);
    int ret(0);
    while (end >= start) {
	int mid = (end + start) / 2;
	if (citations.at(mid) >= (size - mid)) {
	    ret = max(ret, size - mid);
	    end = mid - 1;
	} else {
	    start = mid + 1;
	}
    }
    return ret;
}

int Solution::hIndex2(vector<int>& citations) {
    int n = citations.size();
    vector<int> s(n+1);
    for (int num: citations) {
	if (num < n) ++s[num];
	else ++s[n];
    }
    int cum = 0, i = n + 1;
    while (cum < i) {
	--i;
	cum += s[i];
    }
    return i;
}
