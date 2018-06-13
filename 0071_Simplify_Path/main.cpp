#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("/..");
    Solution* test = new Solution();
    cout << test->simplifyPath(input) << endl;

    return 0;
}

