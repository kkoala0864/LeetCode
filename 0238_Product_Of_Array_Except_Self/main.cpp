#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1,2,3,4};
    Solution* test = new Solution();
    for (const auto& idx : test->productExceptSelf(input))
	cout << idx << " ";
    cout << endl;

    return 0;
}

