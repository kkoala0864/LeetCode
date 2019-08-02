#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> input = {1,2,3};
    cout << test->minScoreTriangulation(input) << endl;
    return 0;
}

