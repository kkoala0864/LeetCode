#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<string> input = {"//", "/ "};
    cout << test->regionsBySlashes(input) << endl;
    return 0;
}

