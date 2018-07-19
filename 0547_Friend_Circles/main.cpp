#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    vector<vector<int>> M = {{1,1,0},
     {1,1,0},
      {0,0,1}};
    Solution* test = new Solution();
    cout << test->findCircleNum(M) << endl;

    return 0;
}

