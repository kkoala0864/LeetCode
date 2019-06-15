#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {20,1,15,3,10,5,8};
    cout << test->longestArithSeqLength(input) << endl;
    return 0;
}

