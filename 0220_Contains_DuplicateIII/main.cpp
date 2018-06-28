#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {10, 100, 11, 9};
    Solution* test = new Solution();
    cout << test->containsNearbyAlmostDuplicate(input, 1, 2) << endl;
    cout << test->containsNearbyAlmostDuplicate2(input, 1, 2) << endl;

    return 0;
}

