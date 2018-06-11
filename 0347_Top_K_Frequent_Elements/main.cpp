#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {1,1,1,2,2,3};
    Solution* test = new Solution();
    vector<int> ret = test->topKFrequent(input, 2);

    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;
    return 0;
}


