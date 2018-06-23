#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {-2, -1, 1, 2};
    Solution* test = new Solution();
    vector<int> ret = test->asteroidCollision(input);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}

