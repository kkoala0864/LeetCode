#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    //vector<int> input = {3, 5, 0, 3, 4};
    //vector<int> input = {-1, 3, 2, 0};
    //vector<int> input = {1, 2, 3, 4};
    //vector<int> input = {3, 5, 0, 3, 4};
    vector<int> input = {-2 ,1 ,1, -2 ,1, 1};
    Solution* test = new Solution();
    cout << test->find132pattern(input) << endl;

    return 0;
}

