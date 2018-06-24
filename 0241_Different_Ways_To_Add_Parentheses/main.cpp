#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string input("-2-4-6");
    Solution* test = new Solution();
    vector<int> ret = test->diffWaysToCompute(input);
    for (const auto& idx : ret) {
	cout << idx << endl;
    }

    return 0;
}

