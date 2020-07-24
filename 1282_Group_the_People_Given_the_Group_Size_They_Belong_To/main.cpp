#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
    vector<vector<int>> ret = test->groupThePeople(groupSizes);
    for (auto iter : ret) {
	for (auto inner : iter) {
		cout << inner << " ";
	}
	cout << endl;
    }
    return 0;
}

