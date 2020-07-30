#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    string input = "()(())()";
    vector<int> ret = test->maxDepthAfterSplit(input);
    for (const auto iter : ret) {
	cout << iter << " ";
    }
    cout << endl;
    return 0;
}

