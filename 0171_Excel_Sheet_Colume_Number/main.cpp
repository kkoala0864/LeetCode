#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("AB");
    Solution* test = new Solution();
    cout << test->titleToNumber(input) << endl;

    return 0;
}

