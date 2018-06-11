#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<string> input = {"0201","0101","0102","1212","2002"};
    Solution* test = new Solution();
    cout << test->openLock(input, "0202") << endl;
    cout << test->openLock2(input, "0202") << endl;

    return 0;
}

