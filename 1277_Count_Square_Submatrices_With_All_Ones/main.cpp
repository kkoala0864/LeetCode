#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> input = {
	    {0,1,1,1},
	    {1,1,1,1},
	    {0,1,1,1}
    };
    cout << test->countSquares(input) << endl;
    return 0;
}

