#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<vector<int>> graph = {{1,2}, {2,3}, {5}, {0}, {5}, {}, {}};
    Solution* test = new Solution();
    vector<int> res = test->eventualSafeNodes(graph);
    for (const auto& val : res) {
	cout << val << " ";
    }
    cout << endl;

    return 0;
}

