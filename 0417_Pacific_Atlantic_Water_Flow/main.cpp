#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<vector<int>> input = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    //vector<vector<int>> input = {{1,1}, {1,1}, {1,1}};
    Solution* test = new Solution();
    vector<pair<int, int>> ret = test->pacificAtlantic(input);
    for (const auto& idx : ret) {
	cout << idx.first << " : " << idx.second << endl;
    }
    cout << endl;
    vector<pair<int, int>> ret2 = test->pacificAtlanticBFS(input);
    for (const auto& idx : ret2) {
	cout << idx.first << " : " << idx.second << endl;
    }
    return 0;

}

