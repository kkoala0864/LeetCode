#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution* test = new Solution();
    cout << test->findKthLargest(nums, 4) << endl;

    return 0;
}

