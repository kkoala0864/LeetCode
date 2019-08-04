#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> input = {{1,1,0,0}};
    cout << test->largest1BorderedSquare(input) << endl;
    return 0;
}

