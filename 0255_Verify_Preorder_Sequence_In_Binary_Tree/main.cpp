#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {5,2,6,1,3};
    Solution* test = new Solution();
    cout << test->verifyPreorder(input) << endl;

    return 0;
}

