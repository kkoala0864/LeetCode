#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    //vector<int> input = {1,2,1,6,7,3,1};
    vector<int> input = {1,2,1};
    Solution* test = new Solution();
    for (const auto& idx : test->nextGreaterElements(input)) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}

