#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1, 1, 1, 1, 1};
    Solution* test = new Solution();
    cout << test->findTargetSumWays(input, 3) << endl;
    cout << test->findTargetSumWaysDP(input, 3) << endl;

    return 0;
}

