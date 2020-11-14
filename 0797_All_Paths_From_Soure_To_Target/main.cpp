#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    auto ret = test->allPathsSourceTarget(graph);
    for (auto iter1 : ret) {
	for (auto iter2 : iter1) {
		cout << iter2 << " ";
	}
	cout << endl;
    }
    return 0;
}

