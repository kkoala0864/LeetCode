#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    string input("AAAA");
    cout << test->characterReplacement(input, 0) << endl;
    return 0;
}

