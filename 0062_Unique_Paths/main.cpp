#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    Solution* test = new Solution();
    cout << test->uniquePaths(10, 10) << endl;
    return 0;
}

