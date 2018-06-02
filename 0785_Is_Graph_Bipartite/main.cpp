#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    Solution* test = new Solution();
    //vector<vector<int>> input = {{4,1},{0,2},{1,3},{2,4},{3,0}};
    //vector<vector<int>> input = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<vector<int>> input = {{1,3},{0,2},{1,3},{0,2}};
    cout << test->isBipartite(input) << endl;

    return 0;
}

