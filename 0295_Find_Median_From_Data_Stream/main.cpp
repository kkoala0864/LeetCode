#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    test->addNum(1);
    test->addNum(2);
    cout << test->findMedian() << endl;
    test->addNum(3);
    cout << test->findMedian() << endl;
    return 0;
}

