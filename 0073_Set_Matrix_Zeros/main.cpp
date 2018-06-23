#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<vector<int>> input = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    Solution* test = new Solution();
    test->setZeroes(input);
    for (const auto& lv1 : input) {
	for (const auto& lv2 : lv1) {
	    cout << lv2 << " ";
	}
	cout << endl;
    }

    return 0;
}

