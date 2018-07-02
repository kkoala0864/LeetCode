#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {
    vector<pair<int, int>> input = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution* test = new Solution();
    vector<pair<int, int>> ret = test->reconstructQueue(input);
    for (const auto& idx : ret) {
	cout << "[" << idx.first << "," << idx.second << "] ";
    }
    cout << endl;

    return 0;
}

