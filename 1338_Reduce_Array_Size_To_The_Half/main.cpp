#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {3,3,3,3,5,5,5,2,2,7};
    cout << test->minSetSize(input) << endl;
    return 0;
}

