#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {3,1,2,4};
    cout << test->combinationSum4(input, 4) << endl;
    return 0;
}

