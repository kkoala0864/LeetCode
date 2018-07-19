#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<vector<int>> Map = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
    Solution* test = new Solution();
    cout << test->calculateMinimumHP(Map) << endl;

    return 0;
}

