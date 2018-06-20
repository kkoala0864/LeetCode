#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    //string input("9,3,4,#,#,1,#,#,2,#,6,#,#");
    //string input("9,3,4,#,#,1,#,#,#,2,#,6,#,#");
    string input("#,#,#");
    Solution* test = new Solution();
    cout << test->isValidSerialization(input) << endl;

    return 0;
}

