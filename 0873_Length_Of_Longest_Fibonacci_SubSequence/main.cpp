#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<int> input = {2,4,7,8,9,10,14,15,18,23,32,50};
    Solution* test = new Solution();
    cout << test->lenLongestFibSubseq(input) << endl;
    return 0;
}

