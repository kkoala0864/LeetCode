#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {1,2,3,4,5,6,7};
    cout << test->largestSumOfAverages(input,4) << endl;
    return 0;
}

