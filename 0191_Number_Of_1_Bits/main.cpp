#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    uint32_t input = 4;
    Solution* test = new Solution();
    cout << test->hammingWeight(input) << endl;
    return 0;
}

