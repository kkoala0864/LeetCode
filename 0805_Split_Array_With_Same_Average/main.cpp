#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {9990,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
    Solution* test = new Solution();
    bool ret = test->splitArraySameAverage(input);
    cout << ret << endl;

    return 0;
}

