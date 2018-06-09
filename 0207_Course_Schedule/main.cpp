#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

using namespace std;
int main(void) {
    Solution* test = new Solution();
    vector<pair<int, int>> input = {{2,0},{1,0},{3,1},{3,2},{1,3}};
    cout << test->canFinish(4, input) << endl;
    cout << test->canFinish2(4, input) << endl;

    return 0;
}

