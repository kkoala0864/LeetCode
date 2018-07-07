#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();

    vector<int> input = {3, 2, 4};
    auto ret = test->twoSum(input, 6);
    for (const auto& val : ret) {
	cout << val << " ";
    }
    cout << endl;


    return 0;
}

