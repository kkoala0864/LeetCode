#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string str1("a");
    string str2("b");
    Solution* test = new Solution();
    cout << test->checkInclusion(str1, str2) << endl;
    return 0;
}

