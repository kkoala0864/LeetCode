#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {2,7,9,3,1};
    Solution* test = new Solution();
    cout << test->rob(input) << endl;

    return 0;
}

