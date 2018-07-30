#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    string input("D");
    Solution* test = new Solution();
    vector<int> ret = test->findPermutation(input);
    for (const auto& val : ret) {
	cout << val << " ";
    }
    cout << endl;

    return 0;
}

