#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    vector<int> cost = {10, 15, 20};
    Solution* test = new Solution();
    cout << test->minCostClimbingStairs(cost) << endl;

    return 0;
}

