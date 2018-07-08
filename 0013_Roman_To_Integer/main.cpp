#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("MCMXCIV");
    Solution* test = new Solution();
    cout << test->romanToInt(input) << endl;

    return 0;
}

