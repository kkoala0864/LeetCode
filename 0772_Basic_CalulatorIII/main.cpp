#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("1+(2*3)*3+(2*3)");
    Solution* test = new Solution();
    cout << test->calculate(input) << endl;

    return 0;
}

