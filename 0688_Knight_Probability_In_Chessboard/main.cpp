#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->knightProbability(8,30,6,4) << endl;
    //cout << test->knightProbability(3,2,0,0) << endl;
    return 0;
}

