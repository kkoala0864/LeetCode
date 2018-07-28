#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<pair<int, int>> edges = {{2,3},{1,2},{1,3}};
    Solution* test = new Solution();
    cout << test->countComponents(4, edges) << endl;
    cout << test->countComponentsPC(4, edges) << endl;

    return 0;
}

