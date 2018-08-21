#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("cbba");
    Solution* test = new Solution();
    cout << test->longestPalindromeSubseq2(input) << endl;

    return 0;
}

