#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<int> nums = {1, 5, 2};
    Solution* test = new Solution();
    cout << test->PredictTheWinner(nums) << endl;
    return 0;
}

