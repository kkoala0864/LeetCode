#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1,2,3,3,4,5};
    Solution* test = new Solution();
    cout << test->isPossible(input) << endl;

    return 0;
}

