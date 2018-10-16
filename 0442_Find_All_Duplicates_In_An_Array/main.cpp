#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<int> input = {4,3,2,7,8,2,3,1};
    Solution* test = new Solution();
    auto res = test->findDuplicates(input);
    for (const auto& val : res) {
	cout << val << endl;
    }
    return 0;
}

