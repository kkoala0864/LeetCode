#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<int> input = {1,2,3};
    Solution* test = new Solution();
    vector<vector<int>> res = test->subsets(input);
    for (const auto& vec : res) {
	for (const auto& ele : vec) {
	    cout << ele << " ";
	}
	cout << endl;
    }
    return 0;
}

