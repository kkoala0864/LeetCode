#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {9,9};
    cout << test->maxTurbulenceSize(input) << endl;
    return 0;
}

