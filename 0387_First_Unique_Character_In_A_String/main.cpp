#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    string input("loveleetcode");
    Solution* test = new Solution();
    cout << test->firstUniqChar(input) << endl;

    return 0;
}

