#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<int> input = {7215807,6967211,5551998,6632092,2802439,821366,2465584,9415257,8663937,3976802,2850841,803069,2294462,8242205,9922998};
    Solution* test = new Solution();
    cout << test->makesquare(input) << endl;
    return 0;
}

