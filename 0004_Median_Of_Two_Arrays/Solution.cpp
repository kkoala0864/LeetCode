#include <Solution.h>
#include <iostream>

using namespace std;

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<int>* bigger = size1 > size2 ? &nums1 : &nums2;
    vector<int>* smaller = bigger == &nums1 ? &nums2 : &nums1;
    int n = bigger->size();
    int m = smaller->size();
    int start = 0;
    int end = m;
    int half_len = (m + n + 1) / 2;
    while (end >= start) {
	int i = (end + start) / 2;
	int j = half_len - i;
	if (i > 0  && smaller->at(i-1) > bigger->at(j)) {
	    end = i - 1;
	} else if (i < m && smaller->at(i) < bigger->at(j-1)) {
	    start = i + 1;
	} else {
	    int max_of_left(0);
	    int min_of_right(0);

	    if (i == 0) max_of_left = bigger->at(j-1);
	    else if (j == 0) max_of_left = smaller->at(i-1);
	    else max_of_left = max(smaller->at(i-1), bigger->at(j-1));

	    if ((m+n) & 1)
		return max_of_left;

	    if (i == m) min_of_right = bigger->at(j);
	    else if (j == n) min_of_right = smaller->at(i);
	    else min_of_right = min(smaller->at(i), bigger->at(j));

	    return (max_of_left + min_of_right) / 2.0;
	}
    }
}
