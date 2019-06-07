#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    //vector<int> input = {1,15,7,9,2,5,10};
    vector<int> input = {2, 1, 4, 3};
    Solution* test = new Solution();
    cout << test->maxSumAfterPartitioning(input, 3) << endl;
    return 0;
}

// 1, 7777, 9999, 99
// 1 + 28 + 36 + 18 = 84
