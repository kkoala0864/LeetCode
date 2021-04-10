#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> coins = {2};
    cout << test->coinChange(coins, 3) << endl;
    return 0;
}

