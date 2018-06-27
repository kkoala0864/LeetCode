#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("aabbcccbcbaabaabdbddasdewe");
    Solution* test = new Solution();
    cout << test->reorganizeString(input) << endl;

    return 0;
}

