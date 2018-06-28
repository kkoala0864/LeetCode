#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {11, 15};
    Solution* test = new Solution();
    cout << test->hIndex(input) << endl;

    return 0;
}

