#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<int> input = {2, 2, 1, 1};
    Solution* test = new Solution();
    vector<vector<int>> ret = test->permuteUnique(input);
    for (const auto& lv1 : ret) {
	for (const auto& lv2 : lv1) {
	    cout << lv2 << " ";
	}
	cout << endl;
    }

    ret = test->permuteUnique2(input);
    cout << endl;
    for (const auto& lv1 : ret) {
	for (const auto& lv2 : lv1) {
	    cout << lv2 << " ";
	}
	cout << endl;
    }
    return 0;
}

