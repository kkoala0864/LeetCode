#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    //string input("bb");
    string input("aaaa");
    Solution* test = new Solution();
    cout << test->longestPalindrome(input) << endl;
    cout << test->longestPalindromeDP(input) << endl;

    return 0;
}

