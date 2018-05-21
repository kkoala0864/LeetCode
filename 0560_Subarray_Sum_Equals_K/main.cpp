#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    //vector<int> input { 0,0,0,0,0,0,0,0,0,0 };
    vector<int> input { 1, 1, 1 };
    cout << test->subarraySum(input, 2) << endl;
    cout << test->Brute(input, 2) << endl;

    return 0;
}

