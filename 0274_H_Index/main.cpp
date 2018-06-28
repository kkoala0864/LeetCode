#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {3,0,6,1,5};
    Solution* test = new Solution();
    cout << test->hIndex(input) << endl;
    cout << test->hIndex2(input) << endl;

    return 0;
}

