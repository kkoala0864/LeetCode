#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {33,53,12,64,50,41,45};
    cout << test->wiggleMaxLength(input) << endl;
    return 0;
}

