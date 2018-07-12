#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<pair<int, int>> input = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    Solution* test = new Solution();
    cout << test->validTree(5, input) << endl;

    return 0;
}

