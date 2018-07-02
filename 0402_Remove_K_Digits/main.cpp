#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("1234567890");
    Solution* test = new Solution();
    cout << test->removeKdigits(input,9) << endl;

    return 0;
}

