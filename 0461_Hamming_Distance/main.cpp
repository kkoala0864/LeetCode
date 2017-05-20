#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    cout << "result: " << test->hammingDistance(1,4) << endl;
    cout << "result: " << test->hammingDistance(3,1) << endl;
    return 0;
}

