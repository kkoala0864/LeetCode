#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string s("abc");
    string t("ahbgdc");
    Solution* test = new Solution();
    cout << test->isSubsequence(s, t) << endl;
    cout << test->isSubsequence2(s, t) << endl;

    return 0;
}

