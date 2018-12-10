#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<int> input = {3,1,2,5,7,4};
    Solution* test = new Solution();
    cout << test->sumSubarrayMinsStack(input) << endl;
    return 0;
}

