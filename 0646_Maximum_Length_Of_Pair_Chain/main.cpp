#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<vector<int>> input = {{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    Solution* test = new Solution();
    cout << test->findLongestChain(input) << endl;
    cout << test->findLongestChainII(input) << endl;
    return 0;
}

