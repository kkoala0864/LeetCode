#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution* test = new Solution();
    vector<int> ret = test->dailyTemperatures(input);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}

