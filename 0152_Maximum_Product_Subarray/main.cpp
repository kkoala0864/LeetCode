#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {2,3,-2,4};
    Solution* test = new Solution();
    cout << test->maxProduct2(input) << endl;

    return 0;
}

