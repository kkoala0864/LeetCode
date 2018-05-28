#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    cout << test->isScramble("abcde", "bacde") << endl;

    return 0;
}

