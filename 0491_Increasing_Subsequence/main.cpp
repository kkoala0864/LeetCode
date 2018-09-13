#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    Solution* test = new Solution();
    vector<vector<int>> result = test->findSubsequences(input);
    cout << result.size() << endl;
    //for (const auto& vec : result) {
    //    for (const auto& ele : vec) {
    //        cout << ele << " ";
    //    }
    //    cout << endl;
    //}

    return 0;
}

