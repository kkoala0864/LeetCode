#include <Solution.h>
#include <iostream>

using namespace std;


void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0 ; i < nums2.size() ; ++i) {
	nums1.at(m+i) = nums2.at(i);
	for (int j = m+i ; j > 0 ; --j) {
	    if (nums1.at(j) < nums1.at(j-1)) swap(nums1.at(j), nums1.at(j-1));
	}
    }
}

