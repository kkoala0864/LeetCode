#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    //vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    vector<vector<int>> heights = {{4,3,4,10,5,5,9,2},{10,8,2,10,9,7,5,6},{5,8,10,10,10,7,4,2},{5,1,3,1,1,3,1,9},{6,4,10,6,10,9,4,6}};
    cout << test->minimumEffortPath(heights) << endl;
    return 0;
}

