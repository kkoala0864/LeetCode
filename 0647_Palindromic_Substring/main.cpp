#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    string input("abc");
    Solution* test = new Solution();
    cout << test->countSubstrings(input) << endl;

    return 0;
}

