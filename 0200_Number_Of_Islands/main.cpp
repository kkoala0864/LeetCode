#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<vector<char>> input = {{'1','1'}};
    Solution* test = new Solution();
    cout << test->numIslands(input) << endl;

    return 0;
}

