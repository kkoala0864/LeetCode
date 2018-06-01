#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<string> input = {"0000"};
    Solution* test = new Solution();
    cout << test->openLock(input, "8888") << endl;

    return 0;
}

