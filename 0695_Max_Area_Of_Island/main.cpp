#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<vector<int>> grid = {{1,1,0,0,0},
	                        {1,1,0,0,0},
				{0,0,0,1,1},
				{0,0,0,1,1}};
    Solution* test = new Solution();
    cout << test->maxAreaOfIsland(grid) << endl;
    return 0;
}

