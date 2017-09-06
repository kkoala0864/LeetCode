#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    Solution* test = new Solution();
    cout << test->isUgly(2147483647) << endl;
    cout << test->isUgly(6) << endl;
    cout << test->isUgly(8) << endl;
    cout << test->isUgly(14) << endl;

    return 0;
}

