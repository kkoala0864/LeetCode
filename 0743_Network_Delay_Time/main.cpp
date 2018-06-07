#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    //vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    //cout << test->networkDelayTime(times, 4, 2) << endl;

    //vector<vector<int>> times = {{1,2,1},{2,3,2},{1,3,4}};
    //cout << test->networkDelayTime(times, 3, 1) << endl;

    vector<vector<int>> times = {{3,5,78},{2,1,1},{1,3,0},{4,3,59},{5,3,85},{5,2,22},{2,4,23},{1,4,43},{4,5,75},{5,1,15},{1,5,91},{4,1,16},{3,2,98},{3,4,22},{5,4,31},{1,2,0},{2,5,4},{4,2,51},{3,1,36},{2,3,59}};
    cout << test->networkDelayTime(times, 5, 5) << endl;
    return 0;
}

