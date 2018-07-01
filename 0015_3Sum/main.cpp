#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    //vector<int> input = {0,0,0};
    //vector<int> input = {1,2,-2,-1};
    Solution* test = new Solution();
    vector<vector<int>> ret = test->threeSum(input);
    for (const auto& lv1 : ret) {
	for (const auto& lv2 : lv1) {
	    cout << lv2 << " ";
	}
	cout << endl;
    }

    return 0;
}

