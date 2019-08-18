#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    //vector<int> input = {2,7,4,1,8,1};
    vector<int> input = {31,26,33,21,40};

    cout << test->lastStoneWeightII(input) << endl;
    return 0;
}

