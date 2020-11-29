#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> interval = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newOne = {{4,8}};
    auto ret = test->insert(interval, newOne);
    for (const auto loop1 : ret) {
	    cout << "[";
	for (const auto loop2 : loop1) {
		cout << loop2 << ",";
	}
	cout << "]";
    }
    cout << endl;
    return 0;
}

