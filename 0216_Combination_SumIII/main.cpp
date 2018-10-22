#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> res = test->combinationSum3(3, 7);
    for (const auto& vec : res) {
	for (const auto& ele : vec) {
	    cout << ele << " ";
	}
	cout << endl;
    }
    return 0;
}

