#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1,2,3,1,2,3};
    Solution* test = new Solution();
    cout << test->rob(input) << endl;

    return 0;
}

