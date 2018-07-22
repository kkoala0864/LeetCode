#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    string word1("a");
    string word2("ab");
    Solution* test = new Solution();
    cout << test->minDistance(word1, word2) << endl;

    return 0;
}

