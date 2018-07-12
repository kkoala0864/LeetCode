#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    string ret = test->numberToWords(1000000);
    cout << "test : |" << ret << "|" << endl;
    return 0;
}

