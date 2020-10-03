#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> edge = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    //vector<vector<int>> edge = {{1,0},{1,2},{3,2},{3,4}};
    //vector<vector<int>> edge = {{1,0},{2,0}};
    //vector<vector<int>> edge = {{4,3},{2,3},{1,2},{1,0}};
    cout << test->minReorder(6, edge) << endl;
    return 0;
}

