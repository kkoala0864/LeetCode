#include <Solution.h>
#include <iostream>

using namespace std;

using namespace std;
int main(void) {
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    //vector<vector<int>> input = {{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};
    vector<vector<int>> input = {{1, 1, 0, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 1, 0}, {1, 0, 0, 1, 1, 1, 0, 1, 0, 1}, {0, 0, 1, 0, 0, 1, 1, 0, 0, 1}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 1, 1, 1}, {1, 1, 0, 0, 1, 0, 1, 0, 1, 1}};
    Solution* test = new Solution();
    //vector<vector<int>> ret = test->updateMatrix(input);
    vector<vector<int>> ret2 = test->updateMatrix2(input);
    //for (const auto& lv1 : ret) {
    //    for (const auto& lv2 : lv1) {
    //        cout << lv2 << " ";
    //    }
    //    cout << endl;
    //}

    for (const auto& lv1 : ret2) {
	for (const auto& lv2 : lv1) {
	    cout << lv2 << " ";
	}
	cout << endl;
    }
    return 0;
}

