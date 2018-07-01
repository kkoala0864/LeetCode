#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("123");
    Solution* test = new Solution();
    cout << test->numDecodings(input) << endl;
    return 0;
}

