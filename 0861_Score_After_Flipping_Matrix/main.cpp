#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> input = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    //vector<vector<int>> input = {{1,1},{0,1},{0,1},{0,0}};
    cout << test->matrixScore(input) << endl;
    return 0;
}

