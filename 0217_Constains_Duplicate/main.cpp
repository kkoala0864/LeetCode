#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {1,1,1,3,3,4,3,2,4,2};
    cout << test->containsDuplicate(input) << endl;
    return 0;
}

