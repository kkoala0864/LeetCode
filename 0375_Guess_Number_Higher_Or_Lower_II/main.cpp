#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    for (int i = 1 ; i <= 7 ; ++i) {
        cout << i << " : " << test->getMoneyAmount(i) << endl;
    }
    cout << test->getMoneyAmount(20) << endl;
    return 0;
}

