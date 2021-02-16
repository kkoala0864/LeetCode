#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    cout << test->longestConsecutive(input) << endl;
    return 0;
}

