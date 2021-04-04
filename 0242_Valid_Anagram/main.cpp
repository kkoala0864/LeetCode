#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    string input1("rat");
    string input2("car");
    cout << test->isAnagram(input1, input2) << endl;
    return 0;
}

