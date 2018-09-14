#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    //vector<vector<int>> input = {{1},{2},{3},{}};
    vector<vector<int>> input = {{1,3},{3,0,1},{2},{0}};
    Solution* test = new Solution();
    cout << test->canVisitAllRooms(input) << endl;
    return 0;
}

