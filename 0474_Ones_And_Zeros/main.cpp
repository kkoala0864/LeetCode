#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    //vector<string> input = {"10", "0001", "111001", "1", "0"};
    //vector<string> input = {"10", "0001", "111001", "1", "0"};
    vector<string> input = {"10","0001","111001","1","0"};
    cout << test->findMaxForm(input, 4, 3) << endl;
    //cout << test->findMaxForm(input, 5, 3) << endl;
    return 0;
}

