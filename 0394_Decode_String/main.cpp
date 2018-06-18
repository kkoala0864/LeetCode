#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("100[abc]");
    Solution* test = new Solution();
    cout << test->decodeString(input) << endl;

    return 0;
}

