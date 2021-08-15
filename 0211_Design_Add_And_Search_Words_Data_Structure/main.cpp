#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    test->addWord("bad");
    test->addWord("dad");
    test->addWord("mad");
    cout << test->search("pad") << endl;
    cout << test->search("bad") << endl;
    cout << test->search(".ad") << endl;
    cout << test->search("b..") << endl;
    return 0;
}

