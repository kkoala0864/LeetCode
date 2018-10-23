#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<string> res = test->generateParenthesis(3);
    for (const auto& val : res) {
	cout << val << endl;
    }
    return 0;
}

