#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << test->shipWithinDays(weights, 5) << endl;

    return 0;
}

