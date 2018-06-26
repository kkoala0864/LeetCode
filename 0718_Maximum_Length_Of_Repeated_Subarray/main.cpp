#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> A = {0, 1, 1, 1, 1};
    vector<int> B = {1, 0, 1, 0, 1};
    Solution* test = new Solution();
    cout << test->findLength(B, A) << endl;

    return 0;
}

