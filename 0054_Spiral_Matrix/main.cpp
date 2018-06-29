#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<vector<int>> input = {{1,2}, {3,4}, {5,6}, {7,8}};
    Solution* test = new Solution();
    vector<int> ret = test->spiralOrder2(input);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}

