#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    //vector<vector<int>> input = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> input = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    for (const auto& idx : input) {
	for (const auto& idx2 : idx) {
	    cout << idx2 << " ";
	}
	cout << endl;
    }
    cout << endl;
    Solution* test = new Solution();
    test->rotate(input);
    for (const auto& idx : input) {
	for (const auto& idx2 : idx) {
	    cout << idx2 << " ";
	}
	cout << endl;
    }

    return 0;
}

