#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<pair<int, int>> input = {{10,16}, {2,8}, {1,6}, {7,12}};
    Solution* test = new Solution();
    cout << test->findMinArrowShots(input) << endl;

    return 0;
}

