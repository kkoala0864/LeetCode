#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<string> board = {"XXX", "   ", "OOO"};
    Solution* test = new Solution();
    cout << test->validTicTacToe(board) << endl;

    return 0;
}

