#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    //string input("T?T?F?7:T?T?F?3:F?T?0:1:0:6:1:0:5");
    string input("F?1:T?4:5");
    cout << input << endl;
    Solution* test = new Solution();
    cout << test->parseTernary(input) << endl;

    return 0;
}

