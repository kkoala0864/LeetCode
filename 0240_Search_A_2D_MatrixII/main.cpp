#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<vector<int>> input = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    Solution* test = new Solution();
    cout << test->searchMatrix(input, 20) << endl;

    return 0;
}

