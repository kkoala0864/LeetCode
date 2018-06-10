#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    vector<pair<int, int>> input = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    vector<int> ret = test->findMinHeightTrees(6, input);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}

