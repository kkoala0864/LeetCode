#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string str("(()(()))");
    Solution* test = new Solution();
    int ret = test->scoreOfParentheses(str);
    cout << "res : " << ret << endl;

    return 0;
}

