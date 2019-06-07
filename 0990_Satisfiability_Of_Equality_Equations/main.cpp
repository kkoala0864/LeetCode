#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<string> input = {"a==b", "b!=a"};
    cout << test->equationsPossible(input) << endl;
    return 0;
}

