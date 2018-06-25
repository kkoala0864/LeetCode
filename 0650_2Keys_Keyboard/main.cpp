#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {

    Solution* test = new Solution();
    cout << test->minSteps2(30) << endl;
    cout << test->minSteps2(20) << endl;
    return 0;
}

