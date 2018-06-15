#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1,2,3,1};
    Solution* test = new Solution();
    cout << test->findPeakElement(input) << endl;

    return 0;
}

