#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {10,9,2,5,3,7,101,18};
    Solution* test = new Solution();
    cout << test->lengthOfLIS(input) << endl;

    return 0;
}

