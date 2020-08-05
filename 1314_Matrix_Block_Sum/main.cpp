#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> input = {{1,2,3}, {4,5,6},{7,8,9}};
    vector<vector<int>> ret = test->matrixBlockSum(input, 2);
    cout << endl;
    for (auto x : ret) {
	for (auto y : x) {
		cout << y << " ";
	}
	cout << endl;
    }
    cout << endl;
    return 0;
}

