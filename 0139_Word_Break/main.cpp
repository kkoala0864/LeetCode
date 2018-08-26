#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<string> dict = {"apple", "pen"};
    string input = "applepenapple";
    Solution* test = new Solution();
    cout << test->wordBreak(input, dict) << endl;

    return 0;
}

