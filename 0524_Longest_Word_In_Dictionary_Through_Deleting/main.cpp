#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    //vector<string> input = {"ale","apple","monkey","plea"};
    vector<string> input = {"a", "b", "c"};
    Solution* test = new Solution();
    cout << test->findLongestWord("abpcplea", input) << endl;

    return 0;
}

