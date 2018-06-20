#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<char> input = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    Solution* test = new Solution();
    test->reverseWords(input);
    for (const auto& idx : input) {
	cout << idx << " ";
    }
    cout << endl;
    return 0;
}

