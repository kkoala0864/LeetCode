#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution* test = new Solution();
    cout << test->findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

