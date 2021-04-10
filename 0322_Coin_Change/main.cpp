#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> coins = {1,2,5};
    cout << test->coinChange(coins, 11) << endl;
    return 0;
}

