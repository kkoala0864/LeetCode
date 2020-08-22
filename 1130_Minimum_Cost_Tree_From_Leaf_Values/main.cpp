#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {7,12,8,10};
    cout << test->mctFromLeafValues(input) << endl;
    return 0;
}

