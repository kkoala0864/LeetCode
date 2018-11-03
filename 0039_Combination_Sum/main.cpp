#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<int> candidates = {2,3,5};
    Solution* test = new Solution();
    vector<vector<int>> res = test->combinationSum(candidates, 8);
    for (const auto& vec : res) {
	for (const auto& val : vec) {
	    cout << val << " ";
	}
	cout << endl;
    }
    return 0;
}

