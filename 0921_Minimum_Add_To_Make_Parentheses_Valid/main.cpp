#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    string input("()))((");
    cout << test->minAddToMakeValid(input) << endl;
    return 0;
}

