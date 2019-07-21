#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {4, 3, 2, 3, 5, 2, 1};
    //vector<int> input = {10,10,10,7,7,7,7,7,7,6,6,6};
    //vector<int> input = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //vector<int> input = {2,2,2,2,3,4,5};
    cout << test->canPartitionKSubsets(input, 4) << endl;
    return 0;
}

