#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    Solution* test = new Solution();
    cout << test->maxSubArray(input) << endl;

    return 0;
}

