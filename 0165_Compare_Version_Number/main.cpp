#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string version1("1.0.1");
    string version2("1");
    Solution* test = new Solution();
    cout << test->compareVersion(version1, version2) << endl;

    return 0;
}

