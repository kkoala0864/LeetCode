#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    Solution* test = new Solution();
    vector<pair<int, int>> ret = test->getSkyline(buildings);
    for (const auto& idx : ret) {
	cout << idx.first << " : " << idx.second << endl;
    }
    return 0;
}

