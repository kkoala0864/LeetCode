#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    vector<int> input = {5,7,7,8,8,10};
    Solution* test = new Solution();
    vector<int> ret = test->searchRange(input, 8);
    cout << ret.at(0) << " : " << ret.at(1) << endl;

    return 0;
}

