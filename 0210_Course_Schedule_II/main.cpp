#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<pair<int, int>> input = {{1,0}, {2, 0}, {3, 2}, {4,1}};
    Solution* test = new Solution();
    vector<int> ret = test->findOrder(5, input);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;
    return 0;
}

